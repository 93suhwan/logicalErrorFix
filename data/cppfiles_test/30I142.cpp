#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  bool HAST = 0;
  if (HAST) {
    int t;
    cin >> t;
    for (int tt = 0, _tt = (t); tt < _tt; ++tt) {
      solve();
      cout << '\n';
      cout.flush();
    }
  } else {
    solve();
  }
}
vector<int> prime_factors_vi(int n) {
  vector<int> factors;
  if (n % 2 == 0) {
    factors.push_back(2);
    while (n % 2 == 0) n = n / 2;
  }
  for (int i = 3; (i <= sqrt(n)) && (n > 1); i = i + 2) {
    if (n % i == 0) {
      factors.push_back(i);
      while (n % i == 0) n = n / i;
    }
  }
  if (n > 2) factors.push_back(n);
  return factors;
}
void dfs(vector<int> &a_group, vector<vector<int>> &d,
         map<int, vector<int>> &ps, set<int> &up, int node, int group_i) {
  a_group[node] = group_i;
  for (int div : d[node]) {
    if (!((up).find(div) != (up).end())) {
      up.insert(div);
      for (int child : ps[div]) {
        if (a_group[child] == -1) {
          dfs(a_group, d, ps, up, child, group_i);
        }
      }
    }
  }
}
bool one(int group1, int group2, vector<vector<int>> &group_a,
         vector<set<int>> &group_div) {
  for (int ai : group_a[group1]) {
    for (int di : group_div[group2]) {
      if (ai % di == 1) return 1;
    }
  }
  return 0;
}
void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0, _i = (n); i < _i; ++i) cin >> a[i];
  vector<vector<int>> d(n);
  map<int, vector<int>> ps;
  for (int i = 0, _i = (n); i < _i; ++i) {
    d[i] = prime_factors_vi(a[i]);
    for (int di : d[i]) {
      ps[di].push_back(i);
    }
  }
  vector<int> a_group(n, -1);
  int group_count = 0;
  set<int> up;
  for (int i = 0, _i = (n); i < _i; ++i) {
    if (a_group[i] == -1) {
      dfs(a_group, d, ps, up, i, group_count);
      group_count++;
    }
  }
  vector<set<int>> group_div(group_count);
  vector<vector<int>> group_a(group_count);
  for (int i = 0, _i = (n); i < _i; ++i) {
    for (int di : d[i]) {
      group_div[a_group[i]].insert(di);
    }
    group_a[a_group[i]].push_back(a[i]);
  }
  for (int qi = 0, _qi = (q); qi < _qi; ++qi) {
    int a1, a2;
    int g1, g2;
    cin >> a1 >> a2;
    g1 = a_group[a1 - 1];
    g2 = a_group[a2 - 1];
    if (g1 == g2) {
      cout << 0;
    } else {
      bool in_one_move = one(g1, g2, group_a, group_div);
      if (!in_one_move) in_one_move = one(g2, g1, group_a, group_div);
      cout << (in_one_move ? 1 : 2);
    }
    cout << '\n';
    cout.flush();
  }
  cout.flush();
}
