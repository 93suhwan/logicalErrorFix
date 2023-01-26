#include <bits/stdc++.h>
using namespace std;
int n, m;
multiset<pair<long long, pair<int, int>>> s;
map<pair<int, int>, long long> cost;
vector<pair<long long, pair<int, int>>> v;
long long solve() {
  v.clear();
  for (auto i : s) {
    v.push_back(i);
    if (v.size() >= 50) break;
  }
  long long sol = v[0].first + v[1].first + v[2].first;
  for (int i = 0; i < v.size(); i++)
    for (int j = i + 1; j < v.size(); j++) {
      pair<int, int> a = v[i].second;
      pair<int, int> b = v[j].second;
      if (a.first != b.first && a.first != b.second)
        if (a.second != b.first && a.second != b.second)
          sol = min(sol, v[i].first + v[j].first);
    }
  return sol;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    s.insert({c, {a, b}});
    cost[{a, b}] = c;
    cost[{b, a}] = c;
  }
  cout << solve() << '\n';
  int q;
  cin >> q;
  while (q--) {
    int tip;
    cin >> tip;
    if (tip == 1) {
      long long a, b, c;
      cin >> a >> b >> c;
      s.insert({c, {a, b}});
      cost[{a, b}] = c;
      cost[{b, a}] = c;
    } else {
      long long a, b;
      cin >> a >> b;
      long long c = cost[{a, b}];
      if (s.find({c, {a, b}}) == s.end()) swap(a, b);
      s.erase(s.find({c, {a, b}}));
    }
    cout << solve() << '\n';
  }
  return 0;
}
