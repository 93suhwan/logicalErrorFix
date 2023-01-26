#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long c = a % b;
    a = b;
    b = c;
  }
  return a;
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    cin >> n;
    int a[n];
    map<int, int> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
      if (m[a[i]] > 1 || a[i] > n) {
        ans++;
        int p = a[i];
        int q = a[i];
        a[i] = (p / 2) + (q % 2) - 1;
      }
    }
    sort(a, a + n);
    int res = 1;
    for (int i = 0; i < n; i++) {
      if (i + 1 > a[i]) res = 0;
    }
    if (res)
      cout << ans << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
