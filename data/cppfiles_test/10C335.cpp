#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 5;
set<int> st[N];
vector<int> pos[N];
int solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  vector<int> ans(n);
  sort(a.begin(), a.end());
  int color = 1, Min = 1e6;
  for (int i = 0; i < n; i++) {
    if (!st[color].count(a[i])) {
      st[color].insert(a[i]);
      color++;
    } else
      st[0].insert(a[i]);
    if (color == k + 1) color = 1;
  }
  for (int i = 1; i <= k; i++) Min = min(Min, (int)st[i].size());
  vector<int> C(k + 2, 0);
  for (int c = 1; c <= k; c++) {
    for (int x : st[c]) {
      if (C[c] + 1 > Min) continue;
      C[c]++;
      ans[(int)pos[x].back()] = c;
      pos[x].pop_back();
    }
  }
  for (int x : ans) cout << x << " ";
  cout << '\n';
  for (int i = 0; i < k + 2; i++) st[i].clear();
  for (int i = 0; i < n; i++) pos[a[i]].clear();
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
