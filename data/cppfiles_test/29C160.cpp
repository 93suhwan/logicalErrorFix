#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int cnt1 = 0, s = 0, cnt0 = 0;
    for (long long i = 0; i < int(n); ++i) {
      int a;
      cin >> a;
      if (a == 1) cnt1++;
      if (a == 0) cnt0++;
    }
    long long f = (1LL << cnt0);
    long long ans = f * cnt1;
    cout << ans << endl;
  }
  return 0;
}
