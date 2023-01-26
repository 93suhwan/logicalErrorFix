#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const long long INF = 1e15 + 7;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n);
  for (auto& x : v) cin >> x;
  vector<string> s(n);
  for (auto& x : s) cin >> x;
  long long nax = 0;
  vector<long long> ans(m, 0);
  for (int i = 0; i < (1 << n); i++) {
    vector<long long> cnt(m, 0);
    vector<long long> res(m, 0);
    vector<int> flag(n, -1);
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) flag[j] = 1;
      for (int k = 0; k < m; k++) {
        if (s[j][k] == '1') cnt[k] += flag[j];
      }
    }
    vector<pair<long long, long long> > temp;
    for (int j = 0; j < m; j++) temp.push_back({cnt[j], j});
    sort(temp.begin(), temp.end());
    long long num = 1;
    for (auto j : temp) {
      res[j.second] = num;
      num++;
    }
    long long curr = 0;
    for (int j = 0; j < n; j++) {
      long long now = 0;
      for (int k = 0; k < m; k++) {
        if (s[j][k] == '1') now += res[k];
      }
      curr += abs(now - v[j]);
    }
    if (curr >= nax) {
      nax = curr;
      ans = res;
    }
  }
  for (auto i : ans) cout << i << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
