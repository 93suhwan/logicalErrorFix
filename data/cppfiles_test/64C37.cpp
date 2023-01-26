#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream& operator<<(ostream& out, const pair<A, B>& u) {
  return out << "(" << u.first << ", " << u.second << ")";
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream& operator<<(ostream& out, const T_container& u) {
  out << "{";
  string sep;
  for (const T& x : u) out << sep << x, sep = ", ";
  return out << "}";
}
template <typename T>
void dbg_out(string s, T x) {
  cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";
}
template <typename T, typename... Args>
void dbg_out(string s, T x, Args... args) {
  for (int i = 0, b = 0; i < (int)s.size(); i++)
    if (s[i] == '(' || s[i] == '{')
      b++;
    else if (s[i] == ')' || s[i] == '}')
      b--;
    else if (s[i] == ',' && b == 0) {
      cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x
           << "\033[31m | ";
      dbg_out(s.substr(s.find_first_not_of(' ', i + 1)), args...);
      break;
    }
}
const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const int MAX_C = 26;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
struct PolyHash {
  static long long MOD;
  static const int BASE = 10;
  static inline long long add(long long a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
  }
  static inline long long sub(long long a, long long b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
  }
  static inline long long mul(long long a, long long b) { return a * b % MOD; }
  vector<long long> power, pref;
  PolyHash(const string& s) : pref(s.length() + 1) {
    while ((int)power.size() <= (int)s.length())
      power.push_back(power.empty() ? 1 : mul(power.back(), BASE));
    for (int i = 0; i < (int)s.length(); i++)
      pref[i + 1] = add(mul(pref[i], BASE), s[i] - '0');
  }
  long long operator()(int pos, int len) const {
    auto res = sub(pref[pos + len], mul(pref[pos], power[len]));
    if (res < 0)
      ;
    return sub(pref[pos + len], mul(pref[pos], power[len]));
  }
};
bool isPrime(int x) {
  if (x % 2 == 0) return false;
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) return false;
  }
  return true;
}
int gen() {
  auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
  mt19937 gen(seed);
  uniform_int_distribution<int> dist(1e9, 2e9 - 1);
  int base = dist(gen);
  while (!isPrime(base)) base = dist(gen);
  return base;
}
long long PolyHash::MOD = gen();
vector<int> preprocess(const string& s) {
  int n = ((int)s.size());
  vector<int> f(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) f[i] = min(r - i + 1, f[i - l]);
    while (i + f[i] < n && s[f[i]] == s[i + f[i]]) f[i]++;
    if (i + f[i] - 1 > r) l = i, r = i + f[i] - 1;
  }
  return f;
}
void solve(int tc = 0) {
  string s, t;
  cin >> s >> t;
  int n = ((int)s.size()), m = ((int)t.size());
  auto hs = PolyHash(s), ht = PolyHash(t);
  auto check = [&](int p1, int l1, int p2, int l2) {
    if (l1 <= 0 || l2 <= 0 || p1 < 0 || p2 < 0 || p1 + l1 > n || p2 + l2 > n)
      return;
    auto v1 = hs.add(hs(p1, l1), hs(p2, l2));
    auto v2 = ht(0, m);
    if (v1 == v2) {
      cout << p1 + 1 << " " << p1 + l1 << "\n";
      cout << p2 + 1 << " " << p2 + l2 << "\n";
      exit(0);
    }
  };
  for (int i = 0, j = m - 1; j + (m - 1) - 1 < n; i++, j++) {
    check(i, m - 1, j, m - 1);
  }
  string ts = t + "#" + s;
  auto f = preprocess(ts);
  for (int i = m + 1; i < ((int)ts.size()); i++) {
    int j = i - (m + 1);
    check(j, m, j + m, m - f[i]);
    check(j, m, j + m, m - f[i] - 1);
    check(j - (m - f[i]), m - f[i], j, m);
    check(j - (m - f[i] - 1), m - f[i] - 1, j, m);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    solve(t);
  }
}
