#include <bits/stdc++.h>
using namespace std;
template <typename T, size_t N>
int SIZE(const T (&t)[N]) {
  return N;
}
template <typename T>
int SIZE(const T &t) {
  return t.size();
}
string to_string(const string s, int x1 = 0, int x2 = 1e9) {
  return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"';
}
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char c) { return string({c}); }
template <size_t N>
string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) {
  string t = "";
  for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1);
       __iii__ <= __jjj__; ++__iii__) {
    t += b[__iii__] + '0';
  }
  return '"' + t + '"';
}
template <typename A, typename... C>
string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords);
int l_v_l_v_l = 0, t_a_b_s = 0;
template <typename A, typename B>
string to_string(const pair<A, B> &p) {
  l_v_l_v_l++;
  string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
  l_v_l_v_l--;
  return res;
}
template <typename A, typename... C>
string to_string(const A(&v), int x1, int x2, C... coords) {
  int rnk = rank<A>::value;
  string tab(t_a_b_s, ' ');
  string res = "";
  bool first = true;
  if (l_v_l_v_l == 0) res += '\n';
  res += tab + "[";
  x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
  auto l = begin(v);
  advance(l, x1);
  auto r = l;
  advance(r, (x2 - x1) + (x2 < SIZE(v)));
  for (auto e = l; e != r; e = next(e)) {
    if (!first) {
      res += ", ";
    }
    first = false;
    l_v_l_v_l++;
    if (e != l) {
      if (rnk > 1) {
        res += '\n';
        t_a_b_s = l_v_l_v_l;
      };
    } else {
      t_a_b_s = 0;
    }
    res += to_string(*e, coords...);
    l_v_l_v_l--;
  }
  res += "]";
  if (l_v_l_v_l == 0) res += '\n';
  return res;
}
void dbgm() { ; }
template <typename Heads, typename... Tails>
void dbgm(Heads H, Tails... T) {
  cerr << to_string(H) << " | ";
  dbgm(T...);
}
bool custom_compare(pair<int, int> &a, pair<int, int> &b) {
  if (a.second != b.second)
    return a.second < b.second;
  else
    return a.first > b.first;
}
long long calc_power(long long n, long long b, long long modd = -1) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      if (modd == -1)
        res = (res * n);
      else
        res = (res * n) % modd;
    }
    if (modd == -1)
      n = n * n;
    else
      n = n * n % (modd);
    b >>= 1;
  }
  return modd == -1 ? res : res % modd;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long modinv(long long a, long long m) { return calc_power(a, m - 2, m); }
void testcase() {
  int n;
  char c;
  string s;
  cin >> n >> c >> s;
  bool ok = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] != c) ok = 0;
  }
  if (ok) {
    cout << 0 << "\n";
    return;
  }
  for (int i = 2; i <= (n + 1) / 2; i++) {
    bool ok = 1;
    for (int j = i; j <= n; j += i) {
      if (s[j - 1] != c) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cout << 1 << "\n" << i << "\n";
      return;
    }
  }
  cout << 2 << "\n" << n << " " << n - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) testcase();
}
