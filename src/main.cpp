#include <ctime>
#include <random>
#include <vector>
#include <string>
#include <iostream>
#include "include\unordered_set.h"
using namespace std;
using namespace Set;

vector<int> GetRandomVector(size_t size) {
srand(int(time(0)));
vector<int> arr(size);
for (size_t i = 0; i < size; ++i) {
  arr[i] = rand() % size;
}
return arr;
}

int CountRepeats(const vector<int>& arr) {
  int count = 0;
  UnorderedSet elements(arr.size(), true);
  UnorderedSet counted_elements(0, true);
  for (size_t i = 0; i < arr.size(); ++i) {
    string key = to_string(arr[i]);
    bool has_counted = bool(counted_elements.Search(key));
    bool has_writen = bool(elements.Search(key));
    if (has_writen && !has_counted){
    count++;
      counted_elements.Insert(key, arr[i]);
    } 
    else if(!has_writen) elements.Insert(to_string(arr[i]), arr[i]);
  }
  return count;
}

int main() {
  vector<int> arr = GetRandomVector(1000);
  cout << CountRepeats(arr);
  


  return 0;
}