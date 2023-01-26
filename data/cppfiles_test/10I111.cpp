#include <bits/stdc++.h>
using namespace std;
const int tam = 1e9 + 5;
void solve() {
  int n, k;
  cin >> n >> k;
  int mx = n / k;
  vector<pair<int, int> > f(n);
  vector<int> c(k);
  vector<int> ans(n);
  vector<int> a(n);
  for (int i = 0; i < int(n); i++) {
    int aux;
    cin >> aux;
    a[i] = aux;
    f[aux - 1].first++;
    f[aux - 1].second = 0;
  }
  for (int i = 0; i < int(n); i++) {
    if (f[a[i] - 1].first >= k) {
      if (f[a[i] - 1].second < k) {
        ans[i] = f[a[i] - 1].second + 1;
        c[f[a[i] - 1].second]++;
        f[a[i] - 1].second++;
      } else {
        ans[i] = 0;
      }
    }
  }
  for (int i = 0; i < int(n); i++) {
    if (f[a[i] - 1].first >= 1 and f[a[i] - 1].first < k) {
      auto mn = min_element(c.begin(), c.end());
      if (c[mn - c.begin()] < mx) {
        ans[i] = mn - c.begin() + 1;
        c[mn - c.begin()]++;
      }
    }
  }
  for (auto &ai : ans) {
    cout << ai << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
