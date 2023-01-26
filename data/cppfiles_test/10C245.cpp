#include <bits/stdc++.h>
using namespace std;
int n, k;
struct node {
  int x, y;
};
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (k > 1) {
      queue<node> s[k];
      int vis[n];
      node a[n];
      for (int i = 0; i < n; i++) {
        cin >> a[i].x;
        a[i].y = i;
        vis[i] = 0;
      }
      sort(a, a + n, cmp);
      int f = 0;
      int kk = 0;
      while (f < n) {
        if (s[kk].size() != 0 && a[f].x == s[kk].back().x) {
          f++;
          continue;
        } else {
          s[kk].push(a[f]);
          kk = (++kk % k);
        }
        f++;
      }
      kk = 0;
      int ans = s[0].size();
      while (kk < k) {
        int sz = s[kk].size();
        ans = min(ans, sz);
        kk++;
      }
      kk = 0;
      while (kk < k) {
        f = 0;
        while (f < ans) {
          vis[s[kk].front().y] = kk + 1;
          s[kk].pop();
          f++;
        }
        kk++;
      }
      for (int i = 0; i < n - 1; i++) {
        cout << vis[i] << ' ';
      }
      cout << vis[n - 1] << endl;
    } else {
      int a[n];
      int vis[n];
      for (int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = 0;
      }
      cout << 1;
      vis[a[0]] = 1;
      for (int i = 1; i < n; i++) {
        if (vis[a[i]] == 0) {
          cout << " 1";
          vis[a[i]] = 1;
        } else
          cout << " 0";
      }
      cout << endl;
    }
  }
  return 0;
}
