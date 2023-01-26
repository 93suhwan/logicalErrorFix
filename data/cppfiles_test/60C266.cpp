#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long M = 1e18;
long long qpow(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt = 1;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      m[a[i]]++;
    }
    sum = 2 * sum;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      m[a[i]]--;
      if (sum % n == 0) {
        ans += m[sum / n - a[i]];
      }
    }
    cout << ans;
    cout << "\n";
  }
  return 0;
}
