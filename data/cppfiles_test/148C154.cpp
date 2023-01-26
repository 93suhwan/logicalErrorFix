#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
void online_judge() {}
long long pow(long long base, long long power) {
  if (power == 0) return 1;
  long long temp = pow(base, power / 2);
  if (power % 2 == 0) return temp * temp;
  return temp * temp * base;
}
vector<bool> prime(2e6, true);
void sieve(int32_t n) {
  prime[1] = 0;
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == 1) {
      for (long long i = p * p; i <= n; i += p) prime[i] = 0;
    }
  }
}
void solve() {
  long long w, h;
  cin >> w >> h;
  long long k;
  long long min1, min2, min3, min4;
  min1 = min2 = min3 = min4 = 1e9;
  long long max1, max2, max3, max4;
  max1 = max2 = max3 = max4 = -1;
  cin >> k;
  for (long long i = 0; i < k; i++) {
    long long x;
    cin >> x;
    min1 = min(min1, x);
    max1 = max(max1, x);
  }
  cin >> k;
  for (long long i = 0; i < k; i++) {
    long long x;
    cin >> x;
    min2 = min(min2, x);
    max2 = max(max2, x);
  }
  cin >> k;
  for (long long i = 0; i < k; i++) {
    long long x;
    cin >> x;
    min3 = min(min3, x);
    max3 = max(max3, x);
  }
  cin >> k;
  for (long long i = 0; i < k; i++) {
    long long x;
    cin >> x;
    min4 = min(min4, x);
    max4 = max(max4, x);
  }
  long long a1 = abs(max1 - min1) * h;
  long long a2 = abs(max2 - min2) * h;
  long long a3 = abs(max3 - min3) * w;
  long long a4 = abs(max4 - min4) * w;
  cout << max({a1, a2, a3, a4}) << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n = 1, i = 1;
  cin >> n;
  while (i++ <= n) {
    solve();
  }
  return 0;
}
