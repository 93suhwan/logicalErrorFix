#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = n;
  vector<int> mp(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    int mx = max(x, y);
    int mn = min(x, y);
    if (mp[mn] == 0) ans--;
    mp[mn]++;
  }
  int ans1 = ans;
  int q;
  cin >> q;
  vector<int> mp2(n);
  mp2 = mp;
  for (int i = 0; i < q; i++) {
    int ch;
    cin >> ch;
    int prev = -1;
    if (ch == 1) {
      int x, y;
      cin >> x >> y;
      int mx = max(x, y);
      int mn = min(x, y);
      if (mp2[mn] == 0) ans1--;
      mp2[mn]++;
      prev = 1;
    } else if (ch == 2) {
      int x, y;
      cin >> x >> y;
      int mx = max(x, y);
      int mn = min(x, y);
      mp2[mn]--;
      if (mp2[mn] == 0) ans1++;
      prev = 2;
    } else {
      cout << ans1 << endl;
      if (prev == 3) continue;
      ans1 = ans;
      mp2 = mp;
      prev = 3;
    }
  }
}
