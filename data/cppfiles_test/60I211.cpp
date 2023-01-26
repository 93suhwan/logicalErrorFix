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
    int maxval = 0, stt;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (minval > a[i]) {
        minval = a[i];
        stt = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != stt) maxval = max(maxval, (minval & a[i]));
    }
    cout << maxval << endl;
  }
  return 0;
}
