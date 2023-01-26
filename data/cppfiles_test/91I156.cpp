#include <bits/stdc++.h>
using namespace std;
int n, m;
multiset<pair<long long, pair<int, int>>> s, d;
multiset<pair<long long, pair<int, int>>> good[300005], my[300005];
map<pair<int, int>, long long> cost;
long long getmin(long long a, long long b) {
  long long rez = 1e16;
  for (auto i : good[a])
    if (s.find(i) != s.end()) s.erase(s.find(i));
  for (auto i : good[b])
    if (s.find(i) != s.end()) s.erase(s.find(i));
  if (!s.empty()) {
    auto it = s.begin();
    rez = (*it).first;
  }
  for (auto i : good[a])
    if (s.find(i) == s.end()) s.insert(i);
  for (auto i : good[b])
    if (s.find(i) == s.end()) s.insert(i);
  return rez;
}
long long solve() {
  int nr = 0;
  long long sol = 0;
  for (auto i : s) {
    nr++;
    sol += i.first;
    if (nr == 3) break;
  }
  pair<long long, pair<int, int>> x = *s.begin();
  int a = x.second.first;
  int b = x.second.second;
  long long c = cost[{a, b}];
  long long z = getmin(a, b);
  sol = min(sol, c + z);
  for (auto i : good[a]) {
    int p = i.second.first;
    int q = i.second.second;
    if (p != a || q != b) {
      z = getmin(p, q);
      c = cost[{p, q}];
      sol = min(sol, c + z);
    }
  }
  for (auto i : good[b]) {
    int p = i.second.first;
    int q = i.second.second;
    if (p != a || q != b) {
      z = getmin(p, q);
      c = cost[{p, q}];
      sol = min(sol, c + z);
    }
  }
  return sol;
}
void calc(int i) {
  if (!good[i].empty()) {
    for (auto j : good[i])
      if (s.find(j) != s.end()) s.erase(s.find(j));
    good[i].clear();
  }
  for (auto j : my[i]) {
    good[i].insert(j);
    if (good[i].size() >= 3) break;
    if (s.find(j) == s.end()) s.insert(j);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    pair<long long, pair<int, int>> x = {c, {a, b}};
    d.insert({c, {a, b}});
    cost[{a, b}] = c;
    cost[{b, a}] = c;
    my[a].insert(x);
    my[b].insert(x);
  }
  for (int i = 1; i <= n; i++) calc(i);
  cout << solve() << '\n';
  int q;
  cin >> q;
  while (q--) {
    int tip;
    cin >> tip;
    if (tip == 1) {
      long long a, b, c;
      cin >> a >> b >> c;
      d.insert({c, {a, b}});
      pair<long long, pair<int, int>> x = {c, {a, b}};
      cost[{a, b}] = c;
      cost[{b, a}] = c;
      my[a].insert(x);
      my[b].insert(x);
      calc(a);
      calc(b);
    } else {
      long long a, b;
      cin >> a >> b;
      long long c = cost[{a, b}];
      if (d.find({c, {a, b}}) == d.end()) swap(a, b);
      d.erase(d.find({c, {a, b}}));
      pair<long long, pair<int, int>> x = {c, {a, b}};
      my[a].erase(my[a].find(x));
      my[b].erase(my[b].find(x));
      calc(a);
      calc(b);
    }
    cout << solve() << '\n';
  }
  return 0;
}
