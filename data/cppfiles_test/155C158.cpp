#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long inf = 1e7 + 7;
bool cmp(pair<int, int> x, pair<int, int> y) { return x.first < y.first; }
int a[N], res[N];
void solve() {
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  vector<pair<int, int> > v, z;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      v.push_back({a[i], i});
    } else {
      z.push_back({a[i], i});
    }
  }
  sort(v.begin(), v.end(), cmp);
  sort(z.begin(), z.end(), cmp);
  int j = 1;
  for (int i = 0; i < z.size(); i++) {
    res[z[i].second] = j;
    j++;
  }
  for (int i = 0; i < v.size(); i++) {
    res[v[i].second] = j;
    j++;
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) solve();
}
