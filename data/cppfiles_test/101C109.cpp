#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<long long> &a, vector<long long> &b) { return a[1] < b[1]; }
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> x, y;
  for (int i = 0; i < n; i++) {
    long long X;
    cin >> X;
    x.push_back(X);
  }
  for (int i = 0; i < m; i++) {
    long long X;
    cin >> X;
    y.push_back(X);
  }
  vector<vector<long long>> v;
  for (int i = 0; i < k; i++) {
    long long a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  long long ans = 0;
  sort((v).begin(), (v).end());
  int l = 0;
  for (int i = 1; i < n; i++) {
    if (l == k) break;
    while (l < k && v[l][0] <= x[i - 1]) l++;
    map<long long, long long> mp;
    long long first = 0;
    while (l < k && v[l][0] < x[i]) {
      mp[v[l][1]]++;
      l++;
      first++;
    }
    long long tmp = 0;
    for (auto p : mp) tmp += (first - p.second) * p.second;
    tmp /= 2;
    ans += tmp;
  }
  l = 0;
  sort((v).begin(), (v).end(), cmp);
  for (int i = 1; i < m; i++) {
    if (l == k) break;
    while (l < k && v[l][1] <= y[i - 1]) l++;
    map<long long, long long> mp;
    long long first = 0;
    while (l < k && v[l][1] < y[i]) {
      mp[v[l][0]]++;
      l++;
      first++;
    }
    long long tmp = 0;
    for (auto p : mp) tmp += (first - p.second) * p.second;
    tmp /= 2;
    ans += tmp;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
