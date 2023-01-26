#include <bits/stdc++.h>
using namespace std;
long long mi[4];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long w, h;
    cin >> w >> h;
    int k[4] = {0};
    for (int i = 0; i < 4; i++) {
      cin >> k[i];
      long long pos1 = 0, pos2 = 0;
      for (int j = 0; j < k[i]; j++) {
        long long tt;
        cin >> tt;
        if (j == 0) pos1 = tt;
        if (j == k[i] - 1) pos2 = tt;
      }
      mi[i] = pos2 - pos1;
    }
    for (int i = 0; i < 4; i++) {
      if (i < 2)
        mi[i] *= h;
      else
        mi[i] *= w;
    }
    long long mx = -1e9;
    for (int i = 0; i < 4; i++) mx = max(mi[i], mx);
    cout << mx << endl;
  }
}
