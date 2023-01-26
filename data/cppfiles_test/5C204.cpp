#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    vector<bool> vis1(n, false), vis2(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '0' and s2[i] == '1') {
        vis1[i] = true;
        vis2[i] = true;
      }
    }
    if (s2[0] == '1' and s1[1] == '1' and vis2[0] == false and
        vis1[1] == false) {
      vis1[1] = true;
      vis2[0] = true;
    }
    if (s2[n - 1] == '1' and s1[n - 2] == '1' and vis2[n - 1] == false and
        vis1[n - 2] == false) {
      vis1[n - 2] = true;
      vis2[n - 1] = true;
    }
    for (int i = 1; i <= n - 2; i++) {
      if (s2[i] == '1' and s1[i - 1] == '1' and vis1[i - 1] == false and
          vis2[i] == false) {
        vis2[i] = true;
        vis1[i - 1] = true;
      } else if (s2[i] == '1' and s1[i + 1] == '1' and vis1[i + 1] == false and
                 vis2[i] == false) {
        vis2[i] = true;
        vis1[i + 1] = true;
      }
    }
    for (int i = 0; i < n; i++) {
      if (vis2[i] == true) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
