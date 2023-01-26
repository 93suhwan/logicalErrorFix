#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long sum(long long n) {
  long long s = 0;
  while (n > 0) {
    s += n % 10;
    n /= 10;
  }
  return s;
}
long long cnt(long long n) {
  long long s = 0;
  while (n > 0) {
    s++;
    n /= 10;
  }
  return s;
}
vector<long long> printDivisors(long long n) {
  vector<long long> v;
  for (long long i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        v.push_back(i);
      else {
        v.push_back(i);
        v.push_back(n / i);
      }
    }
  }
  return v;
}
void solve() {
  long long x, n;
  cin >> x >> n;
  long long ans = 0;
  if (x % 2 == 0) {
    if (n % 2 == 0) {
      if ((n / 2) % 2 == 1)
        ans = x + 1;
      else
        ans = x;
    } else {
      n--;
      if ((n / 2) % 2 == 1) ans = x + 1;
      if ((n / 2) % 2 == 0) ans = x;
      n++;
      if ((n + 1) % 4 == 0) ans += (n);
      if ((n + 1) % 4 != 0) ans -= (n);
    }
  } else {
    if (n % 2 == 0) {
      if ((n / 2) % 2 == 1)
        ans = x - 1;
      else
        ans = x;
    } else {
      n--;
      if ((n / 2) % 2 == 1) ans = x - 1;
      if ((n / 2) % 2 == 0) ans = x;
      n++;
      if ((n + 1) % 4 == 0) ans -= (n);
      if ((n + 1) % 4 != 0) ans += (n);
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  long long xx = 1;
  cin >> xx;
  for (long long t = 1; t <= xx; t++) {
    solve();
  }
  return 0;
}
