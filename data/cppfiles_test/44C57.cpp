#include <bits/stdc++.h>
class Scanner {
 private:
  static const int BUFFER_SIZE = 1 << 18;
  char buff[BUFFER_SIZE];
  char *buffPos, *buffLim;
  FILE* file;

 public:
  Scanner(FILE* file) {
    this->file = file;
    buffLim = buff + fread(buff, 1, BUFFER_SIZE, file);
    buffPos = buff;
  }

 private:
  inline void flushBuff() {
    buffLim = buff + fread(buff, 1, BUFFER_SIZE, file);
    if (buffLim == buff) {
      *buffLim++ = '\n';
    }
    buffPos = buff;
  }
  inline bool isWS(char t) { return t <= ' '; }
  inline bool isDig(char t) { return t >= '0' && t <= '9'; }
  inline void nextPos() {
    buffPos++;
    if (buffPos == buffLim) {
      flushBuff();
    }
  }

 public:
  inline char getchar() {
    char ch = *buffPos;
    nextPos();
    return ch;
  }
  inline void next(char* s) {
    while (isWS(*buffPos)) {
      nextPos();
    }
    while (!isWS(*buffPos)) {
      *s = *buffPos;
      s++;
      nextPos();
    }
    *s = '\0';
  }
  inline void nextLine(char* s) {
    while (*buffPos != '\n') {
      nextPos();
    }
    if (*buffPos == '\n') {
      nextPos();
    }
    while (*buffPos != '\n') {
      *s++ = *buffPos;
      nextPos();
    }
    *s = '\0';
  }
  inline int nextInt() {
    while (!isDig(*buffPos) && *buffPos != '-') {
      nextPos();
    }
    int sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    int res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos();
    }
    return res * sign;
  }
  inline long long nextLong() {
    while (!isDig(*buffPos) && *buffPos != '-') {
      nextPos();
    }
    long long sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    long long res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos();
    }
    return res * sign;
  }
  inline int n() {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    int res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = res * 10 + (*buffPos - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nl() {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = res * 10 + (*buffPos - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nlm(const int MOD) {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = (res * 10 + (*buffPos - '0')) % MOD;
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline double nextDouble() {
    while (isWS(*buffPos)) {
      nextPos();
    }
    int sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    double res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos();
    }
    if (*buffPos == '.') {
      nextPos();
      double ep = 1;
      while (isDig(*buffPos)) {
        ep *= 0.1;
        res += ep * (*buffPos - '0');
        nextPos();
      }
    }
    return sign * res;
  }
  inline char nextChar() {
    while (isWS(*buffPos)) nextPos();
    char res = *buffPos;
    nextPos();
    return res;
  }
  ~Scanner() { fclose(file); }
};
Scanner sc(stdin);
template <class __TyFirst, class __TySecond>
std::ostream& operator<<(std::ostream& out,
                         const std::pair<__TyFirst, __TySecond>& o);
static std::string cout_list_sep = " ";
template <
    class IterateType, typename = decltype(std::declval<IterateType>().begin()),
    typename = decltype(std::declval<IterateType>().end()),
    typename = typename std::enable_if<std::is_convertible<
        typename std::iterator_traits<
            typename IterateType::iterator>::iterator_category,
        std::input_iterator_tag>::value>::type,
    typename = typename std::enable_if<!std::is_base_of<
        std::string, typename std::decay<IterateType>::type>::value>::type,
    typename value_type = typename IterateType::value_type>
std::ostream& operator<<(std::ostream& out, const IterateType& a) {
  for (const auto& i : a) out << i << cout_list_sep;
  return out;
}
template <class __TyFirst, class __TySecond>
std::ostream& operator<<(std::ostream& out,
                         const std::pair<__TyFirst, __TySecond>& o) {
  out << "(" << o.first << "," << o.second << ")";
  return out;
}
template <typename _ForwardIterator>
void logArray(_ForwardIterator, _ForwardIterator, const char* = 0) {}
namespace Temps {
template <typename _IntType>
class RangeInt {
  static_assert(std::is_integral<_IntType>::value,
                "RangeInt object must have integral value type");

 public:
  class iterator : public std::iterator<std::input_iterator_tag, _IntType,
                                        _IntType, const _IntType*, _IntType> {
    _IntType val, step;

   public:
    using typename std::iterator<std::input_iterator_tag, _IntType, _IntType,
                                 const _IntType*, _IntType>::reference;
    explicit constexpr iterator(int val, int step) noexcept
        : val(val), step(step) {}
    constexpr iterator& operator++() noexcept {
      val += step;
      return *this;
    }
    constexpr iterator operator++(int) noexcept {
      iterator ret = *this;
      val += step;
      return ret;
    }
    constexpr bool operator==(const iterator& rhs) const noexcept {
      return val == rhs.val;
    }
    constexpr bool operator!=(const iterator& rhs) const noexcept {
      return val != rhs.val;
    }
    constexpr reference operator*() const { return val; }
  };
  const _IntType _begin, _step, _end;
  explicit constexpr RangeInt(const _IntType end) noexcept
      : _begin(0), _step(1), _end(end > 0 ? end : 0) {}
  explicit constexpr RangeInt(const _IntType begin, const _IntType end) noexcept
      : _begin(begin), _step(1), _end(end > begin ? end : begin) {}
  explicit constexpr RangeInt(const _IntType begin, const _IntType end,
                              const _IntType step)
      : _begin(begin),
        _step(step),
        _end(((step > 0 && end <= begin) || (step < 0 && end >= begin))
                 ? begin
                 : (step > 0
                        ? begin + (end - begin + step - 1) / step * step
                        : begin + (begin - end - step - 1) / (-step) * step)) {}
  constexpr iterator begin() const noexcept { return iterator(_begin, _step); }
  constexpr iterator end() const noexcept { return iterator(_end, _step); }
  constexpr _IntType size() const noexcept { return (_end - _begin) / _step; }
};
template <class IntType, typename = typename std::enable_if<
                             std::is_integral<IntType>::value>::type>
inline constexpr RangeInt<IntType> range(IntType arg1) {
  return RangeInt<IntType>(arg1);
}
template <class IntType, typename = typename std::enable_if<
                             std::is_integral<IntType>::value>::type>
inline constexpr RangeInt<IntType> range(IntType arg1, IntType arg2) {
  return RangeInt<IntType>(arg1, arg2);
}
template <class IntType, typename = typename std::enable_if<
                             std::is_integral<IntType>::value>::type>
inline constexpr RangeInt<IntType> range(IntType arg1, IntType arg2,
                                         IntType arg3) {
  return RangeInt<IntType>(arg1, arg2, arg3);
}
}  // namespace Temps
using Temps::range;
namespace Temps {
template <class T>
inline bool checkMin(T& a, T b) {
  return (b < a ? a = b, 1 : 0);
}
template <class T>
inline bool checkMax(T& a, T b) {
  return (a < b ? a = b, 1 : 0);
}
template <class IntType, typename = typename std::enable_if<
                             std::is_integral<IntType>::value>::type>
IntType gcd(const IntType a, const IntType b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class IntType, typename = typename std::enable_if<
                             std::is_integral<IntType>::value>::type>
IntType lcm(const IntType a, const IntType b) {
  return a / gcd(a, b) * b;
}
template <class ForwardIterator, class OutputIterator>
void dissociate(ForwardIterator __begin, ForwardIterator __end,
                OutputIterator __dest) {
  std::vector<typename std::iterator_traits<ForwardIterator>::_IntType> values(
      __begin, __end);
  std::sort(values.begin(), values.end());
  std::unique(values.begin(), values.end());
  while (__begin != __end) {
    *__dest =
        static_cast<typename std::iterator_traits<OutputIterator>::_IntType>(
            std::distance(
                values.begin(),
                std::lower_bound(values.begin(), values.end(), *__begin)));
    __dest++;
    __begin++;
  }
}
struct once_t {
  bool once = true;
  bool operator()() {
    bool res = once;
    once = false;
    return res;
  }
};
}  // namespace Temps
using Temps::checkMax;
using Temps::checkMin;
namespace Temps {
template <class Type>
class Vector {
  static_assert(std::is_trivial<Type>::value,
                "Temps::Vector can only be used for trival types");

 public:
  typedef Type& reference;
  typedef const Type& const_reference;
  class iterator : public std::iterator<std::random_access_iterator_tag, Type> {
   public:
    friend class Vector;
    using typename std::iterator<std::random_access_iterator_tag,
                                 Type>::difference_type;
    using
        typename std::iterator<std::random_access_iterator_tag, Type>::pointer;
    using typename std::iterator<std::random_access_iterator_tag,
                                 Type>::reference;

   private:
    pointer ptr;
    iterator(pointer ptr) : ptr(ptr) {}

   public:
    bool operator==(const iterator rhs) const { return ptr == rhs.ptr; }
    bool operator!=(const iterator rhs) const { return ptr != rhs.ptr; }
    bool operator<(const iterator rhs) const { return ptr < rhs.ptr; }
    bool operator<=(const iterator rhs) const { return ptr <= rhs.ptr; }
    bool operator>(const iterator rhs) const { return ptr > rhs.ptr; }
    bool operator>=(const iterator rhs) const { return ptr >= rhs.ptr; }
    iterator operator++() { return iterator(++ptr); }
    iterator operator++(int) { return iterator(ptr++); }
    iterator operator--() { return iterator(--ptr); }
    iterator operator--(int) { return iterator(ptr--); }
    iterator operator+(const difference_type dif) const {
      return iterator(ptr + dif);
    }
    iterator operator-(const difference_type dif) const {
      return iterator(ptr - dif);
    }
    iterator operator+=(const difference_type dif) {
      ptr += dif;
      return *this;
    }
    iterator operator-=(const difference_type dif) {
      ptr -= dif;
      return *this;
    }
    difference_type operator-(const iterator& rhs) const {
      return ptr - rhs.ptr;
    }
    operator pointer() { return ptr; }
  };

 protected:
  Type* a = nullptr;
  unsigned int _capacity = 0, _size = 0;
  void __grow_capacity(unsigned int least_size) {
    if (_capacity >= least_size) {
      return;
    }
    if (_capacity == 0) {
      _capacity = 1;
    }
    while (_capacity < least_size) {
      _capacity = _capacity * 2;
    }
    a = static_cast<Type*>(realloc(a, sizeof(Type) * _capacity));
  }

 public:
  Vector() = default;
  explicit Vector(unsigned int size, const Type& initial_value = Type())
      : _capacity(size), _size(size) {
    a = static_cast<Type*>(malloc(sizeof(Type) * _capacity));
    Type *__first = a, *const __last = a + _size;
    while (__first != __last) {
      *__first++ = initial_value;
    }
  }
  Vector(const Vector& rhs) : _capacity(rhs._size), _size(rhs._size) {
    a = static_cast<Type*>(malloc(sizeof(Type) * _capacity));
    Type *__first = a, *__r_p = rhs.a, *const __last = a + _size;
    while (__first != __last) {
      *__first++ = *__r_p++;
    }
  }
  Vector(Vector&& rhs) : _capacity(rhs._capacity), _size(rhs._size) {
    a = rhs.a;
    rhs.a = nullptr;
  }
  Vector(const std::initializer_list<Type>& list)
      : _capacity(
            static_cast<unsigned int>(std::distance(list.begin(), list.end()))),
        _size(_capacity) {
    a = static_cast<Type*>(malloc(sizeof(Type) * _capacity));
    Type* p = a;
    for (const auto& i : list) {
      *p++ = i;
    }
  }
  template <typename Container,
            typename = decltype(std::declval<Container>().begin(),
                                std::declval<Container>().end())>
  Vector(const Container& list)
      : _capacity(
            static_cast<unsigned int>(std::distance(list.begin(), list.end()))),
        _size(_capacity) {
    a = static_cast<Type*>(malloc(sizeof(Type) * _capacity));
    Type* p = a;
    for (const auto& i : list) {
      *p++ = i;
    }
  }
  template <
      typename _InputIterator,
      typename = typename std::enable_if<std::is_convertible<
          typename std::iterator_traits<_InputIterator>::iterator_category,
          std::input_iterator_tag>::value>::type>
  explicit Vector(_InputIterator __first, _InputIterator __last) {
    _size = _capacity =
        static_cast<unsigned int>(std::distance(__first, __last));
    a = static_cast<Type*>(malloc(sizeof(Type) * _capacity));
    Type* p = a;
    while (__first != __last) {
      *p++ = *__first++;
    }
  }
  inline bool empty() const { return _size == 0; }
  inline unsigned int size() const { return _size; }
  inline unsigned int capacity() const { return _capacity; }
  void reserve(unsigned int __capacity) {
    _capacity = __capacity;
    if (_size > _capacity) {
      _size = _capacity;
    }
    a = static_cast<Type*>(realloc(a, sizeof(Type) * _capacity));
  }
  void resize(unsigned int __size) {
    if (_size > __size) {
      _size = __size;
      return;
    }
    __grow_capacity(__size);
    Type *__un = a + _size, *const __ed = a + __size;
    while (__un != __ed) {
      *__un++ = Type();
    }
    _size = __size;
  }
  inline void clear() { resize(0); }
  Vector& operator=(const Vector& rhs) {
    __grow_capacity(rhs._size);
    _size = rhs._size;
    Type* __first = a;
    const Type *const __last = a + _size, *__r_p = rhs.a;
    while (__first != __last) {
      *__first++ = *__r_p++;
    }
    return *this;
  }
  Vector& operator=(Vector&& rhs) {
    _size = rhs._size;
    _capacity = rhs._capacity;
    free(a);
    a = rhs.a;
    rhs.a = nullptr;
    return *this;
  }
  Type operator[](const unsigned int id) const { return a[id]; }
  Type& operator[](const unsigned int id) { return a[id]; }
  Type front() const { return a[0]; }
  Type& front() { return a[0]; }
  Type back() const { return a[_size - 1]; }
  Type& back() { return a[_size - 1]; }
  void pop_back() { _size--; }
  Vector& push_back(const Type& b) {
    __grow_capacity(_size + 1);
    a[_size] = b;
    _size++;
    return *this;
  }
  Vector& push_back(const Vector& rhs) {
    __grow_capacity(_size + rhs._size);
    for (const auto& i : rhs) {
      a[_size++] = i;
    }
    return *this;
  }
  Vector& push_back(const std::initializer_list<Type>& rhs) {
    __grow_capacity(_size + rhs.size());
    for (const auto& i : rhs) {
      a[_size++] = i;
    }
    return *this;
  }
  inline iterator begin() const { return iterator(a); }
  inline iterator end() const { return iterator(a + _size); }
  ~Vector() { free(a); }
};
}  // namespace Temps
using Temps::Vector;
void preInit();
void init();
void solve();
int32_t main() {
  preInit();
  int T;
  T = sc.nextInt();
  while (T--) {
    init();
    solve();
  }
  return 0;
}
void preInit() {}
void init() {}
void solve() {
  int a = sc.n(), b = sc.n();
  if (a == 0 && b == 0) {
    puts("0");
  } else if (a == b) {
    puts("1");
  } else if ((a + b) % 2 == 0) {
    puts("2");
  } else {
    puts("-1");
  }
}
