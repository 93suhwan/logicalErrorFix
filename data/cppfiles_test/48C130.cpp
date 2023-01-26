#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> nxt(n);
    for (int &i : v) {
      cin >> i;
    }
    vector<pair<int, int>> v1(n);
    for (int i = 0; i < n; i++) {
      v1[i] = make_pair(v[i], i);
    }
    sort(v1.begin(), v1.end());
    for (int i = 0; i < n; i++) {
      nxt[v1[i].second] = i;
    }
    bool same = false;
    for (int i = 0; i < n - 1; i++) {
      if (v1[i].first == v1[i + 1].first) same = true;
    }
    vector<int> vis(n);
    int countcycle = 0;
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      if (nxt[i] != i) {
        int countlen = 0;
        while (nxt[i] != i && !vis[i]) {
          vis[i] = 1;
          countlen++;
          i = nxt[i];
        }
        if (countlen % 2 == 0) countcycle++;
      }
    }
    cout << (((countcycle % 2 == 0) || same) ? "YES" : "NO") << endl;
  }
  return 0;
}
