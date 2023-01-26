#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s, q;
    cin >> s;
    cin >> q;
    int l1 = s.length();
    int l2 = q.length();
    vector<int> vis(l1 + 2);
    vector<int> vis2(l1 + 2);
    bool ok = false;
    for (int r = 0; r < l2; r++) {
      for (int i = 0; i < l1 + 1; i++) {
        vis[i] = 0;
        vis2[i] = 0;
      }
      int c = 0;
      int tmp;
      for (int i = 0; i < l1; i++) {
        c = 0;
        tmp = i;
        while (c <= r && i < l1 && q[c] == s[i]) {
          c++;
          i++;
        }
        i--;
        if (c > r) {
          vis[i] = 1;
        }
        i = tmp;
      }
      for (int i = 0; i < l1; i++) {
        c = l2 - 1;
        tmp = i;
        while (c >= r && i < l1 && q[c] == s[i]) {
          c--;
          i++;
        }
        i--;
        if (c < r) {
          vis2[i] = 1;
        }
        i = tmp;
      }
      for (int i = 0; i < l1; i++) {
        if (vis[i] == 1 && vis2[i] == 1) {
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
