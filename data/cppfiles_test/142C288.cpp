#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e5 + 35;
const long long mod = 1e9 + 7;
const long long inf = 2e18;
const double eps = 1e-6;
vector<int> v[MAX];
int n, m;
int M[MAX];
int a[MAX];
bool ch(int x) {
  for (int i = 0; i < n; i++) {
    if (M[i] < x) return 0;
  }
  for (int i = 0; i < m; i++) a[i] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] >= x) {
        a[j]++;
        if (a[j] >= 2) return 1;
      }
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;
        v[j].push_back(x);
      }
    }
    for (int i = 0; i < n; i++) {
      int h = 0;
      for (int j = 0; j < m; j++) h = max(h, v[i][j]);
      M[i] = h;
    }
    int l = 0;
    int r = 1e9;
    int ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ch(mid)) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
      v[i].clear();
      M[i] = 0;
    }
  }
  return 0;
}
