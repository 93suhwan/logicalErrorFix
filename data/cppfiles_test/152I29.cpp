#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  int u = -1e9;
  int lowerlimit = -1e9;
  for (int i = 0; i < n; i++) {
    if (-p[i] > u) {
      u = -p[i];
      a[i] = -p[i];
    } else if (-p[i] > lowerlimit) {
      lowerlimit = -p[i];
      a[i] = -p[i];
    } else if (p[i] > u) {
      u = p[i];
      a[i] = p[i];
    } else if (p[i] > lowerlimit) {
      lowerlimit = p[i];
      a[i] = p[i];
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (int val : a) cout << val << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
