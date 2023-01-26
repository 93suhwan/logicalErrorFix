#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T min(T& x, const T& y) {
  return x > y ? y : x;
}
template <class T>
inline T max(T& x, const T& y) {
  return x < y ? y : x;
}
long long read() {
  long long c = getchar(), Nig = 1, x = 0;
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') Nig = -1, c = getchar();
  while (isdigit(c)) x = ((x << 1) + (x << 3)) + (c ^ '0'), c = getchar();
  return Nig * x;
}
namespace usual {
inline long long gcd(long long a, long long b) {
  long long t;
  while (b != 0) {
    t = a % b;
    a = b;
    b = t;
  }
  return a;
}
inline long long qPow(long long x, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = (res * x);
    k >>= 1;
    x = (x * x);
  }
  return res;
}
inline double qPow1(double x, long long k) {
  if (k == 1) return x;
  long long res = 1.0;
  while (k) {
    if (k & 1) res = (res * x);
    k >>= 1;
    x = (x * x);
  }
  return res;
}
inline long long oula(long long x) {
  long long res = x;
  for (long long i = 2; i <= x / i; i++) {
    if (x % i == 0) {
      res = res / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) res = res / x * (x - 1);
  return res;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
}  // namespace usual
using namespace usual;
priority_queue<int, vector<int>, greater<int> > xiaogen;
priority_queue<int, vector<int>, less<int> > dagen;
const long long inf = 9223372036854775807;
const long long INF = 0x3f3f3f3f;
const int maxn = 1e5 + 7;
const int mod = 1000000007;
map<char, int> mp;
int main() {
  int _ = read();
  while (_--) {
    string s, t;
    cin >> s >> t;
    mp.clear();
    if (t.size() == 1) {
      puts("0");
      continue;
    }
    for (int i = 0; i < 26; i++) {
      mp[s[i]] = i + 1;
    }
    int ans = 0;
    for (int i = 1; i < t.size(); i++) {
      ans += abs(mp[t[i]] - mp[t[i - 1]]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
