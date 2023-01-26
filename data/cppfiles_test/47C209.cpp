#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long hell = 998244353;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long sum1(long long n) {
  long long res = 0;
  for (int i = n; i >= 1; i--) res = (res + i) % mod;
  return res % mod;
}
unsigned long long power(unsigned long long x, long long y, long long p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res % p;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> x(n);
  vector<long long> pos, neg;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (x[i] >= 0)
      pos.push_back(x[i]);
    else
      neg.push_back(x[i]);
  }
  long long ma1 = INT_MIN, ma2 = INT_MIN;
  for (long long i = 0; i < neg.size(); i++) neg[i] = abs(neg[i]);
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  for (long long i = 0; i < pos.size(); i++) {
    ma1 = max(ma1, pos[i]);
  }
  for (long long i = 0; i < neg.size(); i++) {
    ma2 = max(ma2, abs(neg[i]));
  }
  long long ans = 0, f = 0;
  if (ma1 >= ma2) {
    if (pos.size() != 0) {
      for (long long i = pos.size() - 1; i >= 0;) {
        if (f == 0)
          ans += pos[i], f = 1, i = i - k;
        else
          ans += 2 * pos[i], i = i - k;
        if (i < 0) break;
      }
    }
    if (neg.size() != 0) {
      for (long long i = neg.size() - 1; i >= 0;) {
        ans += 2 * neg[i], i = i - k;
        if (i < 0) break;
      }
    }
  } else {
    if (neg.size() != 0) {
      for (long long i = neg.size() - 1; i >= 0;) {
        if (f == 0)
          ans += neg[i], f = 1, i = i - k;
        else
          ans += 2 * neg[i], i = i - k;
        if (i < 0) break;
      }
    }
    if (pos.size() != 0) {
      for (long long i = pos.size() - 1; i >= 0;) {
        ans += 2 * pos[i], i = i - k;
        if (i < 0) break;
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
