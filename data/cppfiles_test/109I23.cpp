#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using pii = pair<int, int>;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const double DINF = 1e100;
const double eps = 1e-8;
const int MOD_1e9 = 1000000007;
const int MOD_998 = 998244353;
template <typename T>
inline void get_min(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
inline void get_max(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
inline void get_unique(vector<T> &vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
inline int sig(double x) { return x < -eps ? -1 : eps < x; }
template <typename T>
inline LL fp(LL a, T n, int mod) {
  if (n < 0) a = fp(a, mod - 2, mod), n = -n;
  LL res = 1;
  for (; n; n >>= 1, a = a * a % mod)
    if (n & 1) res = res * a % mod;
  return res;
}
template <int mod>
class Mint {
 public:
  int x;
  Mint() : x(0) {}
  Mint(int _x) : x(_x) {
    if (x < 0 || x >= mod) x %= mod;
    if (x < 0) x += mod;
  }
  Mint(LL _x) {
    if (_x < 0 || _x >= mod) _x %= mod;
    if (_x < 0) _x += mod;
    x = _x;
  }
  Mint operator-() const { return Mint(x == 0 ? x : mod - x); }
  Mint operator+(const Mint &rhs) const {
    return Mint(x + rhs.x >= mod ? x + rhs.x - mod : x + rhs.x);
  }
  Mint operator-(const Mint &rhs) const {
    return Mint(x - rhs.x < 0 ? x - rhs.x + mod : x - rhs.x);
  }
  Mint operator*(const Mint &rhs) const { return Mint((LL)x * rhs.x % mod); }
  Mint operator/(const Mint &rhs) const {
    return Mint((LL)x * fp(rhs.x, -1, mod) % mod);
  }
  bool operator==(const Mint &rhs) const { return x == rhs.x; }
  bool operator!=(const Mint &rhs) const { return x != rhs.x; }
  Mint &operator+=(const Mint &rhs) {
    x += rhs.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  Mint &operator-=(const Mint &rhs) {
    x -= rhs.x;
    if (x < 0) x += mod;
    return *this;
  }
  Mint &operator*=(const Mint &rhs) {
    x = (LL)x * rhs.x % mod;
    return *this;
  }
  Mint &operator/=(const Mint &rhs) {
    x = (LL)x * fp(rhs.x, -1, mod) % mod;
    return *this;
  }
  friend ostream &operator<<(ostream &out, const Mint &rhs) {
    return out << to_string(rhs.x);
  }
  Mint inv() const { return Mint(fp(x, -1, mod)); }
  template <typename T>
  Mint pow(T k) const {
    return Mint(fp(x, k, mod));
  }
};
class fast_reader {
 private:
  int buff_size;
  char *buff_ptr, *ptr, *tail;
  bool is_open;
  fast_reader(const fast_reader &) = delete;
  fast_reader &operator=(const fast_reader &) = delete;
  inline bool is_digit() const { return '0' <= *ptr && *ptr <= '9'; }
  inline bool is_blank() const { return *ptr <= ' '; }
  template <typename T>
  inline void read_i(T &x) {
    static bool f;
    for (f = false; ptr < tail && !is_digit(); ptr++)
      if (*ptr == '-') f = true;
    for (x = 0; ptr < tail && is_digit(); ptr++)
      x = (x << 1) + (x << 3) + (*ptr & 0xf);
    if (f) x = -x;
  }
  template <typename T>
  inline void read_f(T &x) {
    static char t_buff[64];
    read(t_buff);
    x = atof(t_buff);
  }

 public:
  fast_reader()
      : buff_size(0),
        buff_ptr(nullptr),
        ptr(nullptr),
        tail(nullptr),
        is_open(false) {}
  ~fast_reader() {
    if (is_open) free(buff_ptr), is_open = false;
  }
  template <typename T>
  fast_reader &operator>>(T &x) {
    read(x);
    return *this;
  }
  template <typename T, typename... Args>
  inline void read(T &x, Args &...args) {
    read(x);
    read(args...);
  }
  inline bool is_end() {
    while (ptr < tail && is_blank()) ptr++;
    return ptr >= tail;
  }
  inline void open_alter(int call_size = 1 << 20) {
    if (is_open) throw runtime_error("fast reader is reopened!");
    buff_ptr = (char *)malloc(call_size);
    buff_size = fread(buff_ptr, sizeof(char), call_size, stdin);
    for (; feof(stdin) == 0; call_size <<= 1) {
      buff_ptr = (char *)realloc(buff_ptr, call_size << 1);
      buff_size += fread(buff_ptr + call_size, sizeof(char), call_size, stdin);
    }
    ptr = buff_ptr = (char *)realloc(buff_ptr, buff_size);
    tail = buff_ptr + buff_size;
    is_open = true;
  }
  inline void read(int &x) { read_i(x); }
  inline void read(unsigned int &x) { read_i(x); }
  inline void read(long long &x) { read_i(x); }
  inline void read(unsigned long long &x) { read_i(x); }
  inline void read(float &x) { read_f(x); }
  inline void read(double &x) { read_f(x); }
  inline void read(char *str) {
    while (ptr < tail && is_blank()) ptr++;
    for (; ptr < tail && !is_blank(); str++) *str = *ptr++;
    *str = '\0';
  }
  inline void read(string &s) {
    static char *pre;
    while (ptr < tail && is_blank()) ptr++;
    for (pre = ptr; ptr < tail && !is_blank(); ptr++)
      ;
    s = move(string(pre, ptr));
  }
} reader;
const int maxn = (int)1e5 + 5;
const int maxm = (int)5e5 + 5;
using mint = Mint<MOD_998>;
mint fac[maxn];
mint ifac[maxn];
mint C(int n, int m) { return fac[n] * ifac[m] * ifac[n - m]; }
void work() {
  int n;
  reader >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    reader >> s;
    mp[s]++;
  }
  int B = 0, W = 0, q = 0;
  for (auto pr : mp) {
    for (auto ch : pr.first) {
      if (ch == 'B') B += pr.second;
      if (ch == 'W') W += pr.second;
      if (ch == '?') q += pr.second;
    }
  }
  int d = abs(B - W);
  if (d <= q) {
    mint ans = C(q, d);
    if (mp["WW"] == 0 && mp["BB"] == 0) {
      ans -= mint(2).pow(mp["??"]);
      if (mp["BW"] == 0 && mp["?W"] == 0 && mp["B?"] == 0) ans += 1;
      if (mp["WB"] == 0 && mp["W?"] == 0 && mp["?B"] == 0) ans += 1;
    }
    cout << ans << '\n';
  } else {
    cout << 0 << '\n';
  }
}
int main() {
  reader.open_alter();
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i;
  ifac[maxn - 1] = fac[maxn - 1].inv();
  for (int i = maxn - 2; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1);
  int tc = 1;
  for (int ca = 1; ca <= tc; ca++) {
    work();
  }
  return 0;
}
