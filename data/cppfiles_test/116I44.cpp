#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int maxi = 3e5 + 100;
int n, m, k;
set<int> alfabet;
vector<vector<int> > a;
vector<int> g[maxi];
set<int> liter[maxi];
set<int> zbior;
int odw[maxi];
set<int> zak;
map<int, int> dl;
int odwslo[maxi];
vector<pair<int, int> > eds;
map<pair<int, int>, bool> odweds;
void dfszakslow(int w);
void dfszakliter(int w) {
  if (zak.find(w) != zak.end()) {
    return;
  }
  zak.insert(w);
  for (auto xd : liter[w]) {
    if (!odwslo[xd]) {
      dfszakslow(xd);
    }
  }
}
void dfszakslow(int w) {
  if (odwslo[w]) {
    return;
  }
  odwslo[w] = 1;
  for (auto xd : a[w]) {
    dfszakliter(xd);
  }
}
bool dfs(int w) {
  zbior.insert(w);
  odw[w] = 1;
  bool ans = true;
  if (zak.find(w) != zak.end()) {
    ans = false;
  }
  for (auto xd : g[w]) {
    if (odweds[eds[xd]]) {
      continue;
    }
    odweds[eds[xd]] = true;
    int x = eds[xd].first;
    if (x == w) {
      x = eds[xd].second;
    }
    if (odw[x]) {
      ans = false;
    }
    bool dx = dfs(x);
    ans &= dx;
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  vector<int> zleslowa;
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    vector<int> v;
    set<int> sv;
    multiset<int> mv;
    for (int j = 0; j < c; ++j) {
      int x;
      scanf("%d", &x);
      alfabet.insert(x);
      v.push_back(x);
      liter[x].insert(i);
      sv.insert(x);
      mv.insert(x);
    }
    a.push_back(v);
    for (int j = 1; j < c; ++j) {
      eds.push_back({v[j - 1], v[j]});
      g[v[j]].push_back(eds.size() - 1);
      g[v[j - 1]].push_back(eds.size() - 1);
    }
    if (sv.size() != mv.size()) {
      zleslowa.push_back(i);
    }
  }
  for (auto xd : zleslowa) {
    dfszakslow(xd);
  }
  for (int i = 1; i <= k; ++i) {
    if (odw[i]) {
      continue;
    }
    zbior.clear();
    bool fla = dfs(i);
    if (fla) {
      ++dl[zbior.size()];
    }
  }
  vector<long long> dp(m + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (auto xd : dl) {
      if (xd.first > i) {
        continue;
      }
      dp[i] += dp[i - xd.first] * xd.second;
      dp[i] %= mod;
    }
  }
  printf("%lld\n", dp[m]);
}
