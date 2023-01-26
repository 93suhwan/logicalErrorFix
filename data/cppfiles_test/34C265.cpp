#include <bits/stdc++.h>
using namespace std;
const int MN = 100005;
const int MX = 500005;
const int INF = 1000000007;
const int MOD = 998244353;
int n;
long long a[500005], k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Tc;
  for (cin >> Tc; Tc--;) {
    cin >> n >> k;
    for (int i = 1; i < n + 1; i++) cin >> a[i];
    long long res = -1e9;
    for (int i = n; i >= max(1, n - 300); i--) {
      for (int j = i - 1; j >= max(1, n - 300); j--) {
        res = max(res, 1LL * i * j - k * (a[i] | a[j]));
      }
    }
    cout << res << endl;
  }
  return 0;
}
