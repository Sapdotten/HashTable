#ifndef INCLUDE_UNORDERED_SET_CC
#define INCLUDE_UNORDERED_SET_CC
#include "unordered_set.h"

#include <ctime>
#include <random>
#include <string>
#include <iostream>
namespace Set {
int UnorderedSet::RandomValue() const { return rand() % this->_size; }
UnorderedSet::UnorderedSet(size_t size, bool is_empty) {
  this->_size = size;
  this->_table = new Cell[size];
  this->_pairs_count = 0;
  if (!is_empty) {
    srand(int(time(0)));
    for (int i = 0; i < size; ++i) {
      std::string key = "key_" + std::to_string(i);
      int value = this->RandomValue();
      this->Insert(key, value);
    }
  }
}

UnorderedSet::UnorderedSet(const UnorderedSet& other) {
  this->_size = other._size;
  this->_pairs_count = other._pairs_count;
  this->_table = new Cell[this->_size];
  for (int i = 0; i < this->_size; ++i) {
    this->_table[i].is_used = other._table[i].is_used;
    if (other._table[i].pair)
      this->_table[i].pair =
          new Pair(other._table[i].pair->key, other._table[i].pair->value);
    else
      this->_table[i].pair = nullptr;
  }
}

void UnorderedSet::Swaps(UnorderedSet& other) {
  std::swap(this->_size, other._size);
  std::swap(this->_pairs_count, other._pairs_count);
  std::swap(this->_table, other._table);
}
UnorderedSet& UnorderedSet::operator=(const UnorderedSet& other) {
  UnorderedSet temp(other);
  this->Swaps(temp);
  return *this;
}

UnorderedSet::~UnorderedSet() {
  for (int i = 0; i < this->_size; ++i) {
    delete this->_table[i].pair;
  }
  delete[] this->_table;
}

UnorderedSet::Pair* UnorderedSet::SearchPair(const std::string key) const {
  if (!this->_size) return nullptr;
  const int first_hash = this->Hash(key);
  int hash = first_hash;
  while (this->_table[hash].pair || this->_table[hash].is_used) {
    if (this->_table[hash].pair && this->_table[hash].pair->key == key)
      return this->_table[hash].pair;
    hash++;
    if (hash >= this->_size) hash = 0;
    if (hash == first_hash) return nullptr;
  }
  return nullptr;
}

void UnorderedSet::Insert(std::string key, int value) {
  auto pair = this->SearchPair(key);
  if (pair) {
    pair->value = value;
    return;
  }
  if (this->_pairs_count >= this->_size) this->NewSizeSet();
  int hash = this->Hash(key);
  while ((this->_table[hash].pair)) {
    hash++;
    if (hash >= this->_size) hash = 0;
  }
  this->_table[hash].pair = new Pair(key, value);
  this->_table[hash].is_used = true;
  this->_pairs_count++;
}

bool UnorderedSet::Contains(int value) {
  for (int i = 0; i < this->_size; ++i) {
    if (this->_table[i].pair->value == value) return true;
  }
  return false;
}

int* UnorderedSet::Search(const std::string key) const {
  auto pair = this->SearchPair(key);
  if (pair)
    return &(pair->value);
  else
    return nullptr;
};

bool UnorderedSet::Erase(const std::string key) {
  if (!this->_size) return false;
  int first_hash = this->Hash(key);
  int hash = first_hash;
  while (this->_table[hash].pair || this->_table[hash].is_used) {
    if (this->_table[hash].pair && this->_table[hash].pair->key == key) {
      delete this->_table[hash].pair;
      this->_table[hash].pair = nullptr;
      this->_pairs_count--;
      return true;
    }

    hash++;
    if (hash >= this->_size) hash = 0;
    if (hash == first_hash) return false;
  }
  return false;
}

int UnorderedSet::Count(const std::string key) const {
  auto pair = this->SearchPair(key);
  if (pair)
    return 1;
  else
    return 0;
}

int UnorderedSet::Hash(std::string key) const {
  int h = 0;
  for (auto c : key) {
    h += int((this->_size) * std::fmod((this->_hash_key) * int(c), 1));
  }
  return h % this->_size;
}

void UnorderedSet::NewSizeSet() {
  size_t new_size = this->_size + (this->_size / 2) + 1;
  UnorderedSet temp(new_size, true);
  for (int i = 0; i < this->_size; ++i) {
    if (this->_table[i].pair)
      temp.Insert(this->_table[i].pair->key, this->_table[i].pair->value);
  }
  *this = temp;
}

void UnorderedSet::Print() const {
  for (int i = 0; i < this->_size; ++i) {
    std::cout << "Key: " << this->_table[i].pair->key
              << " Value: " << this->_table[i].pair->value << std::endl;
  }
}
}  // namespace Set
#endif