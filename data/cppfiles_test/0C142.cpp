#include <bits/stdc++.h>
using namespace std;
void f(vector<int> &v, vector<string> &s, int t = 0) {
  if (v.empty()) return;
  if (v.size() == 1) {
    cout << v[0] + 1 << ' ';
    return;
  }
  vector<vector<int>> vv(26);
  for (auto &i : v) vv[s[i][t] - 'A'].emplace_back(i);
  for (auto &i : vv) f(i, s, t + 1);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto &i : s) {
    cin >> i;
    for (int j = 1; j < m; j += 2) i[j] = 155 - i[j];
  }
  vector<int> v(n);
  for (int i = 0; i < n; i++) v[i] = i;
  f(v, s);
  return 0;
}
