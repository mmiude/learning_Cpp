#include "class.h"
#include <numeric>


RunningAverage::RunningAverage(int values): size(values) {
}

void RunningAverage::add_value(int value){
   if (valueList.size() >= size) valueList.pop_back();
   valueList.push_front(value);
}

double RunningAverage::get_average(){
  return accumulate(valueList.begin(), valueList.end(), 0.0) / valueList.size();
}