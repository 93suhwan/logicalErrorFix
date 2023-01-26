#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T>
inline void write(T x) {
  long long i = 20;
  char buf[21];
  buf[20] = '\n';
  do {
    buf[--i] = x % 10 + '0';
    x /= 10;
  } while (x);
  do {
    putchar(buf[i]);
  } while (buf[i++] != '\n');
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b)
    return gcd(a % b, b);
  else
    return gcd(a, b % a);
}
long long exp(long long x, long long n) {
  if (n == 0) return 1;
  if (n == 1) return x % 1000000007;
  if (n % 2 == 0)
    return exp((x * x) % 1000000007, n / 2);
  else
    return exp(x * exp((x * x) % 1000000007, n / 2));
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  long long c1 = 0, c2 = 0, c3 = 0;
  for (long long i = 0; i < s.size(); i += 1) {
    if (s[i] == 'A')
      c1++;
    else if (s[i] == 'B')
      c2++;
    else
      c3++;
  }
  if (c1 <= c2) {
    n -= 2 * c1;
    c2 = c2 - c1;
    if (c2 == c3) {
      n -= 2 * c3;
    }
  }
  if (n == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
