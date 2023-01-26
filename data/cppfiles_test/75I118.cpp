#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<int> temp(k);
    for (int j = 0; j < k; j++) {
      cin >> temp[j];
    }
    a.push_back(temp);
  }
  vector<pair<int, int>> p;
  for (auto x : a) {
    int sz = x.size();
    int pos = sz - 1;
    int maxa = x[pos] + 1;
    for (int i = sz - 2; i >= 0; i--) {
      maxa = max(x[i] + 1, maxa - 1);
    }
    int a1 = maxa;
    int a2 = a1 + sz;
    p.push_back({a1, a2});
  }
  sort(p.begin(), p.end());
  int ans = p[0].second + 1;
  int k1 = p[0].second - p[0].first;
  for (int i = 1; i < n; i++) {
    ans = max(ans, p[i].first - k1);
    k1 += p[i].second - p[i].first;
  }
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
