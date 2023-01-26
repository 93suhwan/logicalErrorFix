#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6 + 10;
const long long mod = 1e9 + 7;
const double eps = 1e-6;
int b[MAX];
int a[MAX];
int m[MAX];
int vis[MAX];
int c[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  int t;
  cin >> t;
  while (t--) {
    vector<int> ans;
    int n;
    cin >> n;
    int mm;
    cin >> mm;
    for (int i = 0; i < n; i++) m[i] = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      if (a[i] <= i) {
        int k = i - a[i];
        m[k]++;
      } else {
        int k = n - a[i];
        k += i;
        m[k]++;
      }
    }
    for (int k = 0; k < n; k++) {
      int h = n - m[k];
      if (h > 2 * mm) continue;
      for (int i = 0; i < n; i++) {
        int s = (i + k) % n;
        c[s] = i;
      }
      int g = 0;
      for (int i = 0; i < n; i++) {
        int s1 = a[i];
        int s2 = c[i];
        b[s2] = s1;
      }
      for (int i = 0; i < n; i++) vis[i] = 0;
      for (int i = 0; i < n; i++) {
        int f = i;
        if (!vis[f]) {
          g++;
          while (!vis[f]) {
            vis[f] = 1;
            f = b[f];
          }
        }
      }
      g = n - g;
      if (g <= mm) {
        ans.push_back(k);
      }
    }
    cout << ans.size() << " ";
    for (auto i : ans) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
