#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <thread>


class Car {
	friend std::ostream &operator<<(std::ostream &out, const Car &car);
public:
	Car(const char* m="Ford", const char *l=nullptr, int ml=0) : model(m), license(l?l:(rand()%2?"FOO-":"BAR-") + std::to_string(rand()%999+1)), mileage(ml?ml:rand()%10000) {}
	~Car() { std::cout << model << " " << license << " deleted" << std::endl; };
	void Read();
	std::string GetLicense() const { return license; }
private:
	std::string model;
	std::string license;
	int mileage;
};

void Car::Read()
{
	//std::cout << "Enter car information" << std::endl;
	// replace the following with your own code
	model = "Seat";
	license = (rand() % 2 ? "ZAP-" : "ZIP-") + std::to_string(rand() % 999 + 1);
	mileage = 10000 + rand() % 10000;
}

std::ostream & operator<<(std::ostream & out, const Car & car)
{
	std::cout << "Model: " << car.model << std::endl << "License: " << car.license << std::endl << "Mileage: " << car.mileage << std::endl;

	return out;
}

/* ---------------------- */

class Website {
public:
	Website(const char *n = nullptr) : name(n ? n : "www.cars" + std::to_string(rand() % 99 + 1) + ".com") {
		threadOn = true;
	}
	~Website() { std::cout << name << " deleted" << std::endl; };
	void advertise(std::shared_ptr<Car> car) {
		std::lock_guard lg(mx);
		listing.push_back((car));
	}

	void print(std::ostream &out = std::cout) {
		std::lock_guard ls(mx);
		std::erase_if(listing, [](const std::weak_ptr<Car> &car){return car.expired();});
		out << name << std::endl;
		for(const auto& car : listing) {
			if ( auto carptr = car.lock(); carptr != nullptr) std::cout << *carptr << std::endl;
		}
		out << name << " end of list" << std::endl;
	}

	void run() {
		while (true) {
			print();
			if (listing.empty() || !threadOn) break;
			std::this_thread::sleep_for(std::chrono::seconds(10));
		}
		std::cout << "thread stopped" << std::endl;
	}

	void setThread(bool value) {
		threadOn = false;
	}

private:
	std::vector<std::weak_ptr<Car>> listing;
	std::string name;
	std::mutex mx;
	bool threadOn;
};

class Dealer {
	friend std::ostream &operator<<(std::ostream &out, const Dealer &dealer);
public:
	Dealer(const char *name_ = "John Doe") : name(name_) {};
	~Dealer() { std::cout << name << " deleted" << std::endl; };
	void buy();
	void sell(std::shared_ptr<Dealer> dealer);
	void add(std::shared_ptr<Car> car) {
		std::lock_guard ls(mx);
		cars.push_back(car);
		for (const auto& site : sites) site->advertise(car);
	}
	void add_site(std::shared_ptr<Website> w) { sites.push_back(w); }
	std::string getName() {
		return name;
	}
private:
	std::string name;
	std::vector<std::shared_ptr<Car>> cars; ; // shared pointer
	std::vector<std::shared_ptr<Website>> sites;  // shared pointer
	std::mutex mx;
};

void Dealer::buy()
{
	auto car = std::make_shared<Car>(); // shared pointer
	car->Read();
	add(car);
}

void Dealer::sell(std::shared_ptr<Dealer> dealer)
{
	std::cout << *dealer; // print my list of cars
	std::cout << "Enter license of car you want to buy" << std::endl;

	std::string license;
	std::cin >> std::ws >> license;
	std::lock_guard ls(mx);
	auto ci = std::find_if(cars.begin(), cars.end(), [&license](std::shared_ptr<Car> c) {return license == c->GetLicense(); });
	if (ci != cars.end()) {
		cars.erase(ci);
	}
}


std::ostream & operator<<(std::ostream & out, const Dealer & dealer)
{
	std::cout << dealer.name << "'s cars for sale" << std::endl;
	for (const auto& car : dealer.cars) std::cout << *car;
	std::cout << "End of " << dealer.name << "'s cars listing" << std::endl;

	return out;
}

/* ---------------------- */



void car_sales()
{
	std::cout << "Car sales started" << std::endl;
	auto wa = std::make_shared<Website>("www.autos.com"); //shared pointer
	auto wb = std::make_shared<Website>("www.bilar.com"); //shared pointer
	auto wc = std::make_shared<Website>("www.cars.com"); //shared pointer
	auto a = std::make_shared<Dealer>("Alan Aldis"); //shared pointer
	auto b = std::make_shared<Dealer>("Bill Munny"); //shared pointer
	{
		auto c = std::make_shared<Dealer>("Casey Ball"); //shared pointer
		auto ca = std::make_shared<Car>(); //shared pointer
		auto cb = std::make_shared<Car>(); //shared pointer

		a->add_site(wa);
		a->add_site(wb);
		b->add_site(wb);
		b->add_site(wc);
		c->add_site(wa);
		c->add_site(wb);
		c->add_site(wc);

		a->buy();
		a->buy();
		a->buy();
		a->buy();

		b->buy();
		b->buy();
		b->buy();

		c->buy();
		c->buy();
		c->add(ca);
		c->add(cb);


		std::thread t1(&Website::run, wa);
		std::thread t2(&Website::run, wb);
		std::thread t3(&Website::run, wc);

		std::cout << *a << *b << *c << std::endl;

		std::string input;
		do {
			std::cout << R"(Select a dealer: a/b/c or "exit")" << std::endl;
			std::cin >> std::ws >> input;
			if (input == "a") a->sell(a);
			if (input == "b") b->sell(b);
			if (input == "c") c->sell(c);
		} while (input != "exit");

		std::cout << *a << *b << *c << std::endl;

		wa->setThread(false);
		wb->setThread(false);
		wc->setThread(false);
		t1.join();
		t2.join();
		t3.join();
	}

	std::cout << "Car sales ended" << std::endl;

}

int main(int argc, char **argv) {
	_CrtMemState s1;
	_CrtMemCheckpoint(&s1);

	srand(time(NULL));

	car_sales();

	_CrtMemState s2,s3;
	_CrtMemCheckpoint(&s2);
	if (_CrtMemDifference(&s3, &s1, &s2)) {
		_CrtDumpMemoryLeaks();
		_CrtMemDumpStatistics(&s3);
	}

	return 0;
}


