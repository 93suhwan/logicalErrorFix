#include <bits/stdc++.h>
using namespace std;
int a[1005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3 + 5, lim5 = 1e5 + 5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int minval = 1e9;
    int maxval = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int l = 1; l <= n; l++) {
      for (int r = l; r <= n; r++) {
        maxval = 0;
        for (int cs = 0; cs <= r - l; cs++) {
          maxval = max(maxval, (a[l + cs] & a[r - cs]));
        }
        for (int cs = 1; cs < l; cs++) maxval = max(maxval, a[cs]);
        minval = min(minval, maxval);
      }
    }
    cout << minval << endl;
  }
  return 0;
}
