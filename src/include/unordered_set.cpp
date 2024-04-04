#ifndef INCLUDE_UNORDERED_SET_CPP
#define INCLUDE_UNORDERED_SET_CPP
namespace Set {
template <typename K, typename T>
class UnorderedSet {
  struct Pair {
    K key;
    T value;
    Pair(K key_, T value_) : key(key_), value(value_){};
  };
  struct Cell {
    bool is_used;
    Pair* pair;
    Cell() : is_used(false), pair(nullptr);
  };
  int* _table;
  double _fill_factor;
  static inline double _MAX_FILL_FACTOR = 0.9;
  static inline double _hash_key = 777777.0 / 64.0;
  size_t _size;
  size_t _pairs_count;

  int Hash(K key) const;
  bool IsOverflowed() const;
  Set NewSizeSet() const; 

 public:
  UnorderedSet(size_t size, bool is_empty = true);
  UnorderedSet(const UnorderedSet& other);
  UnorderedSet operator=(const UnorderedSet& other);
  void Swaps(UnorderedSet& other);
  ~UnorderedSet();
  void Print() const;
  void Insert(K key, T value);
  bool Contains(T value);
  T* Search(K key) const;
  bool Erase(K key);
  int Count(key) const;


};
/*Класс должен предоставлять, как минимум, следующие функции:

Конструктор пустой хэш таблицы заданного размера
Конструктор, заполняющий хэш таблицу случайными значениями согласно вашему
заданию. Конструктор копирования; Деструктор; Оператор присваивания; void
print() – печать содержимого; void insert(K key, T value) – вставка значения по
ключу; void insert_or_assign(K key, T value) - вставка или присвоение значения
по ключу. bool contains(T value) -  проверка наличия элемента; T* search(K key)
- поиск элемента; bool erase(K key) – удаление элемента по значению; int
count(key) - возвращает количество элементов по соответствующему ключу.
*/

}  // namespace Set
#endif