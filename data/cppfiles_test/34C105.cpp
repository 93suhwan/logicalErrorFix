#include <bits/stdc++.h>
namespace cm {
class logger {
 private:
  std::ostream* out;
  std::string sep = "\x2c\x20";
  bool _assert_exit = true;
  std::string c_red = "\033[0;31m";
  std::string c_green = "\033[0;32m";
  std::string c_yellow = "\033[0;33m";
  std::string c_blue = "\033[0;34m";
  std::string c_magenta = "\033[0;35m";
  std::string c_cyan = "\033[0;36m";
  std::string c_red_bold = "\033[1;31m";
  std::string c_green_bold = "\033[1;32m";
  std::string c_yellow_bold = "\033[1;33m";
  std::string c_blue_bold = "\033[1;34m";
  std::string c_magenta_bold = "\033[1;35m";
  std::string c_cyan_bold = "\033[1;36m";
  std::string c_reset = "\033[0m";
  std::string get_color(std::string name) {
    if (name == "red") return c_red;
    if (name == "green") return c_green;
    if (name == "yellow") return c_yellow;
    if (name == "blue") return c_blue;
    if (name == "magenta") return c_magenta;
    if (name == "cyan") return c_cyan;
    if (name == "red bold") return c_red_bold;
    if (name == "green bold") return c_green_bold;
    if (name == "yellow bold") return c_yellow_bold;
    if (name == "blue bold") return c_blue_bold;
    if (name == "magenta bold") return c_magenta_bold;
    if (name == "cyan bold") return c_cyan_bold;
    if (name == "reset") return c_reset;
    return "";
  }

 public:
  logger(std::ostream& out) : out(&out) {}
  logger& set_ostream(std::ostream& out) {
    this->out = &out;
    return *this;
  }
  logger& set_sep(const std::string& sep) {
    this->sep = sep;
    return *this;
  }
  logger& assert_exit() {
    _assert_exit = true;
    return *this;
  }
  logger& assert_noexit() {
    _assert_exit = false;
    return *this;
  }
  logger& endl() {
    *out << std::endl;
    return *this;
  }
  logger& log() { return *this; }
  template <class Ta, class Tb, class... Tc>
  logger& log(const Ta& a, const Tb& b, Tc... c) {
    return log(a).log(sep).log(b, c...);
  }
  template <class Ta, typename = decltype(std::cout << std::declval<Ta>())>
  logger& log(const Ta& a) {
    *out << a;
    return *this;
  }
  template <class T, typename = decltype(std::declval<T>().begin()),
            typename = decltype(std::declval<T>().end()),
            typename = typename std::enable_if<!std::is_base_of<
                std::string, typename std::decay<T>::type>::value>::type,
            typename value_type = typename T::value_type>
  logger& log(const T& container) {
    log("{");
    for (auto it = container.begin(); it != container.end(); ++it) {
      if (it != container.begin()) log(sep);
      log(*it);
    }
    log("}");
    return *this;
  }
  template <class Ta, class Tb>
  logger& log(const std::pair<Ta, Tb>& x) {
    return log("(").log(x.first, x.second).log(")");
  }
  template <class... T>
  logger& log(const std::tuple<T...>&) {
    return log("<tuple>");
  }
  template <class T>
  logger& hint(const T& x, std::string color = "cyan") {
    color = get_color(color);
    return log(color).log(x).log("\x3a\x20").log(c_reset);
  }
  template <class... T>
  logger& operator()(T... value) {
    return log(value...).endl();
  }
  template <class... T>
  logger& _assert(const std::string& file, int line, const std::string& raw,
                  bool value, const std::string& info_str, T... info) {
    if (!value) {
      endl();
      hint(file, "magenta")
          .hint(line, "magenta")
          .log(c_yellow)
          .log("Assertion `")
          .log(c_yellow_bold)
          .log(raw)
          .log(c_yellow)
          .log("` failed")
          .log(c_reset)
          .endl();
      if (info_str != "") hint("detail", "magenta").hint(info_str)(info...);
      if (_assert_exit) exit(0);
    }
    return *this;
  }
};
namespace impl {
logger see_logger(std::cout);
}
}  // namespace cm
namespace cm {
template <class Type, size_t buf_size>
class buffer_reader {
 protected:
  FILE* src;
  Type* const buff;
  Type* buff_end;
  Type* buff_pos;
  void flush() {
    buff_end = buff + fread(buff, sizeof(Type), buf_size, src);
    buff_pos = buff;
    if (buff_end == buff) {
      *buff_end = '\0';
    }
  }

 public:
  buffer_reader(FILE* src) : src(src), buff(new Type[buf_size]) { flush(); }
  buffer_reader(const buffer_reader&) = delete;
  buffer_reader(buffer_reader&&) = delete;
  buffer_reader& operator=(const buffer_reader&) = delete;
  buffer_reader& operator=(buffer_reader&&) = delete;
  Type get() const { return *buff_pos; }
  Type next() {
    Type result = get();
    buff_pos++;
    if (buff_pos == buff_end) flush();
    return result;
  }
  ~buffer_reader() {
    fclose(src);
    delete[] buff;
  }
};
using optimal_reader = buffer_reader<char, 1 << 16>;
template <class BufferReader>
class scanner : protected BufferReader {
 private:
  using BufferReader::get;
  using BufferReader::next;
  inline bool is_ws(char c) { return c <= ' '; }
  inline bool is_cr(char c) { return c == '\n' || c == '\r'; }
  int get_sign() {
    while (!isdigit(get()) && get() != '-') next();
    if (get() == '-') return next(), -1;
    return 1;
  }

 public:
  scanner() = delete;
  using BufferReader::BufferReader;
  char next_char() {
    while (is_ws(get())) next();
    return next();
  }
  char* next_token(char* s) {
    while (is_ws(get())) next();
    while (!is_ws(get())) *s++ = next();
    *s = '\0';
    return s;
  }
  char* next_line(char* s) {
    while (is_ws(get())) next();
    while (!is_cr(get())) *s++ = next();
    *s = '\0';
    return s;
  }
  int next_int() {
    int sign = get_sign();
    int result = 0;
    while (isdigit(get())) result = result * 10 + (next() - '0');
    return sign * result;
  }
  long long next_long() {
    int sign = get_sign();
    long long result = 0;
    while (isdigit(get())) result = result * 10 + (next() - '0');
    return sign * result;
  }
  long long next_modint(long long mod) {
    get_sign();
    long long result = 0;
    while (isdigit(get())) result = (result * 10 + (next() - '0')) % mod;
    return result;
  }
  double next_double() {
    int sign = get_sign();
    double result = 0;
    while (isdigit(get())) result = result * 10 + (next() - '0');
    if (get() == '.') {
      next();
      double cur_ep = 0.1;
      while (isdigit(get())) result += cur_ep * (next() - '0'), cur_ep *= 0.1;
    }
    return sign * result;
  }
};
}  // namespace cm
namespace cm {
template <class T>
inline bool check_min(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool check_max(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
struct once_t {
  bool once = true;
  bool operator()() { return once ? (once = false, true) : false; }
};
}  // namespace cm
using cm::check_max;
using cm::check_min;
template <class A, class B>
inline __attribute__((always_inline)) std::pair<A, B> operator+(
    const std::pair<A, B>& lhs, const std::pair<A, B>& rhs) {
  return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}
template <class A, class B>
inline __attribute__((always_inline)) std::pair<A, B> operator-(
    const std::pair<A, B>& lhs, const std::pair<A, B>& rhs) {
  return std::make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
}
template <class A, class B>
inline __attribute__((always_inline)) std::pair<A, B>& operator+=(
    std::pair<A, B>& lhs, const std::pair<A, B>& rhs) {
  lhs.first += rhs.first;
  lhs.second += rhs.second;
  return lhs;
}
template <class A, class B>
inline __attribute__((always_inline)) std::pair<A, B>& operator-=(
    std::pair<A, B>& lhs, const std::pair<A, B>& rhs) {
  lhs.first -= rhs.first;
  lhs.second -= rhs.second;
  return lhs;
}
template <class T>
std::vector<T>& operator+=(std::vector<T>& a, const std::vector<T>& b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}
template <class T>
std::vector<T>& operator+=(std::vector<T>& a, const T& b) {
  a.insert(a.end(), b);
  return a;
}
template <class T>
std::vector<T>& operator+=(std::vector<T>& a, T&& b) {
  a.insert(a.end(), std::forward<T>(b));
  return a;
}
template <class T>
std::vector<T> operator+(std::vector<T> a, const std::vector<T>& b) {
  a += b;
  return a;
}
template <class T>
std::vector<T> operator+(std::vector<T> a, T& b) {
  a += b;
  return a;
}
template <class T>
std::vector<T> operator+(std::vector<T> a, T&& b) {
  a += std::forward<T>(b);
  return a;
}
cm::scanner<cm::optimal_reader> sc(stdin);
constexpr int W = 8192;
std::vector<int> updated[W];
int last_update[W];
bool ans[W];
int n;
int main() {
  ans[0] = true;
  for (int i = 0; i < W; i++) {
    updated[i].push_back(0);
    last_update[i] = W;
  }
  n = sc.next_int();
  for (int i = 0; i < n; i++) {
    int x = sc.next_int();
    for (int key : updated[x]) {
      int to = key ^ x;
      ans[to] = true;
      for (int j = x + 1; j < last_update[to]; j++) updated[j].push_back(to);
      check_min(last_update[to], x);
    }
    updated[x].clear();
  }
  std::cout << std::accumulate(ans, ans + W, 0) << std::endl;
  for (int i = 0; i < W; i++)
    if (ans[i]) printf("%d ", i);
  return 0;
}
