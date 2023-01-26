#include <bits/stdc++.h>
using namespace std;
using Vi = vector<int>;
using i64 = long long;
using ll = long long;
using Pi = pair<int, int>;
mt19937 mrand(time(0));
int rnd(int x) { return mrand() % x; }
const int N = 500005;
const int M = 40005;
static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE* in = stdin;
  char cur = 0;
  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
  }
  inline void tie(int) {}
  inline explicit operator bool() { return cur != -1; }
  inline static bool is_blank(char c) { return c <= ' '; }
  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }
  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }
  inline FastInput& operator>>(string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }
  template <typename T>
  inline FastInput& read_integer(T& n) {
    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }
  template <typename T>
  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(
      T& n) {
    return read_integer(n);
  }
  inline FastInput& operator>>(__int128& n) { return read_integer(n); }
  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type
  operator>>(T& n) {
    n = 0;
    if (skip_blanks()) {
      string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;
static struct FastOutput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t buf_pos = 0;
  static constexpr int TMP_SIZE = 1 << 20;
  char tmp[TMP_SIZE];
  FILE* out = stdout;
  inline void put_char(char c) {
    buf[buf_pos++] = c;
    if (buf_pos == BUF_SIZE) {
      fwrite(buf, 1, buf_pos, out);
      buf_pos = 0;
    }
  }
  ~FastOutput() { fwrite(buf, 1, buf_pos, out); }
  inline FastOutput& operator<<(char c) {
    put_char(c);
    return *this;
  }
  inline FastOutput& operator<<(const char* s) {
    while (*s) {
      put_char(*s++);
    }
    return *this;
  }
  inline FastOutput& operator<<(const string& s) {
    for (int i = 0; i < (int)s.size(); i++) {
      put_char(s[i]);
    }
    return *this;
  }
  template <typename T>
  inline char* integer_to_string(T n) {
    char* p = tmp + TMP_SIZE - 1;
    if (n == 0) {
      *--p = '0';
    } else {
      bool is_negative = false;
      if (n < 0) {
        is_negative = true;
        n = -n;
      }
      while (n > 0) {
        *--p = (char)('0' + n % 10);
        n /= 10;
      }
      if (is_negative) {
        *--p = '-';
      }
    }
    return p;
  }
  template <typename T>
  inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
    return integer_to_string(n);
  }
  inline char* stringify(__int128 n) { return integer_to_string(n); }
  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(
      T n) {
    sprintf(tmp, "%.17f", n);
    return tmp;
  }
  template <typename T>
  inline FastOutput& operator<<(const T& n) {
    auto p = stringify(n);
    for (; *p != 0; p++) {
      put_char(*p);
    }
    return *this;
  }
} fast_output;
int main() {
  ios::sync_with_stdio(false);
  fast_input.tie(0);
  int n, m;
  fast_input >> n >> m;
  int BL = 300;
  vector<Pi> a(n);
  for (int i = 0; i < n; ++i) fast_input >> a[i].first >> a[i].second;
  Vi ans(m + 1);
  vector<vector<Pi>> nd(n);
  vector<Pi> day(m);
  for (int i = 0; i < m; ++i) {
    fast_input >> day[i].first >> day[i].second;
    --day[i].second;
    if (day[i].first == 1)
      nd[day[i].second].emplace_back(i, m - 1);
    else
      nd[day[i].second].back().second = i - 1;
  }
  for (int i = 0; i < n; ++i) {
    int x = a[i].first, y = a[i].second;
    if (x + y < BL) continue;
    for (auto j : nd[i]) {
      for (int k = j.first; k <= j.second; k += x + y) {
        if (k + x <= j.second) {
          ++ans[k + x];
          --ans[min(k + x + y, j.second + 1)];
        }
      }
    }
  }
  for (int i = 1; i < m; ++i) ans[i] += ans[i - 1];
  vector<Vi> B(BL);
  for (int i = 1; i < BL; ++i) B[i].resize(i, 0);
  Vi vis(n);
  for (int i = 0; i < m; ++i) {
    int x = a[day[i].second].first, y = a[day[i].second].second;
    if (x + y >= BL) continue;
    if (day[i].first == 1) {
      for (int j = i + x; j < i + x + y; ++j) ++B[x + y][j % (x + y)];
      vis[day[i].second] = i;
    } else {
      int t = vis[day[i].second];
      for (int j = t + x; j < t + x + y; ++j) --B[x + y][j % (x + y)];
    }
    for (int j = 1; j < BL; ++j) ans[i] += B[j][i % j];
  }
  for (int i = 0; i < m; ++i) fast_output << ans[i] << '\n';
  return 0;
}
