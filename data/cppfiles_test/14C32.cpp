#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
int tmp[N];
int n;
struct vcl {
  int x, y, d;
};
void solve() {
  cin >> n;
  vector<vcl> v;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] > a[j]) {
        for (int k = i; k <= j; k++) tmp[k] = a[k];
        for (int k = i + 1; k <= j; k++) a[k] = tmp[k - 1];
        a[i] = tmp[j];
        v.push_back({i, j, j - i});
      }
    }
  }
  cout << v.size() << '\n';
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].x << ' ' << v[i].y << ' ' << v[i].d << '\n';
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
