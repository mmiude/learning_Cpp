
#ifndef CLASS_H
#define CLASS_H

#include <deque>

class RunningAverage {
  public:
    explicit RunningAverage(int values);
    void add_value(int value);
    double get_average();

  private:
    int size;
    std::deque<int> valueList;
};

#endif //CLASS_H
