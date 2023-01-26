#include <bits/stdc++.h>
using namespace std;
long long maxn[4];
long long minn[4];
long long ans[4];
long long maxans;
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(maxn, 0, sizeof(maxn));
    memset(minn, 0x7f, sizeof(minn));
    maxans = -1;
    int w, h;
    cin >> w >> h;
    for (int i = 0; i < 4; i++) {
      int n;
      cin >> n;
      for (int j = 0; j < n; j++) {
        long long x;
        cin >> x;
        maxn[i] = max(maxn[i], x);
        minn[i] = min(minn[i], x);
      }
      ans[i] = maxn[i] - minn[i];
    }
    for (int i = 0; i < 4; i++) {
      if (i == 0 || i == 1) {
        maxans = max(maxans, ans[i] * h);
      } else {
        maxans = max(maxans, ans[i] * w);
      }
    }
    cout << maxans << endl;
  }
  return 0;
}
