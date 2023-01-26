#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long MOD = 1000000007;
const int N = 2e5;
const int M = 1e5;
const int LOG = 18;
const int MAX = 200000;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string a;
    cin >> a;
    string b;
    cin >> b;
    int ans = INF;
    for (int j = 0; j < 2; j++) {
      int cnt0 = 0, cnt1 = 0;
      for (int k = 0; k < n; k++) {
        if (a[k] != b[k]) {
          if (a[k] == '0') {
            cnt0++;
          }
          if (a[k] == '1') {
            cnt1++;
          }
        }
      }
      if ((cnt0 + cnt1) % 2 == j && cnt1 >= cnt0 && cnt0 >= cnt1 - 1) {
        ans = min(ans, cnt0 + cnt1);
      }
      for (int k = 0; k < n; k++) {
        b[k] = '0' + (1 - (b[k] - '0'));
      }
    }
    if (ans == INF) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}
