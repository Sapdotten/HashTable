#ifndef INCLUDE_UNORDERED_SET_H
#define INCLUDE_UNORDERED_SET_H
#include <string>
namespace Set {
class UnorderedSet {
  struct Pair {
    std::string key;
    int value;
    Pair(std::string key_, int value_) : key(key_), value(value_){};
  };
  struct Cell {
    bool is_used;
    Pair* pair;
    Cell() : is_used(false), pair(nullptr){};
  };
  Cell* _table;
  const double _hash_key = 777777.0 / 64.0;
  size_t _size;
  size_t _pairs_count;

  int Hash(std::string key) const;
  void NewSizeSet();
  int RandomValue() const;
  Pair* SearchPair(const std::string key) const;

 public:
  UnorderedSet(size_t size, bool is_empty);
  UnorderedSet(const UnorderedSet& other);
  UnorderedSet& operator=(const UnorderedSet& other);
  void Swaps(UnorderedSet& other);
  ~UnorderedSet();
  void Print() const;
  void Insert(std::string key, int value);
  bool Contains(int value);
  int* Search(const std::string key) const;
  bool Erase(const std::string key);
  int Count(const std::string key) const;
};



}  // namespace Set
#endif