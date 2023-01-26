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
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int res = a[1];
    for (int i = 2; i <= n; i++) {
      res = (res & a[i]);
    }
    cout << res << endl;
  }
  return 0;
}
