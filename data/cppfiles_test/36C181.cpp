#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
double pi = acos(-1.0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long powerm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % M;
    y = y >> 1;
    x = (x * x) % M;
  }
  return res % M;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 'a' << '\n';
      continue;
    }
    if (n & 1) {
      string s = "";
      int k = n / 2 - 1;
      for (int i = 0; i < k; i++) s += 'b';
      s += 'a';
      for (int i = 0; i < k + 1; i++) s += 'b';
      s += 'c';
      cout << s << '\n';
    } else {
      string s = "";
      int k = n / 2 - 1;
      for (int i = 0; i < k; i++) s += 'b';
      s += 'a';
      for (int i = 0; i < k + 1; i++) s += 'b';
      cout << s << '\n';
    }
  }
  return 0;
}
