#include <bits/stdc++.h>
const long long inf = 2e9;
using namespace std;
vector<long long> pos;
string f(long long cur, vector<pair<long long, long long>> &g, string &s) {
  if (cur == -1) return "";
  string before = f(g[cur].first, g, s);
  pos.push_back(cur);
  return before + s[cur] + f(g[cur].second, g, s);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<pair<long long, long long>> g(n);
  vector<pair<long long, long long>> parent(n);
  parent[0] = make_pair(-1, -1);
  for (int i = 0; i < int(n); ++i) {
    long long a, b;
    cin >> a >> b;
    a--, b--;
    g[i] = make_pair(a, b);
    if (a != -1) parent[a] = make_pair(i, 0);
    if (b != -1) parent[b] = make_pair(i, 1);
  }
  string initial = f(0, g, s);
  vector<bool> taken(n);
  vector<long long> suffix(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], (long long)initial[i]);
  }
  cerr << initial << endl;
  for (int i = 0; i < int(initial.size() - 1); ++i) {
    if (initial[i] > initial[i + 1])
      continue;
    else if (initial[i] == initial[i + 1]) {
      bool good = 0;
      for (int j = i; j < int(initial.size() - 1); ++j) {
        if (initial[j] != initial[j + 1]) {
          good = initial[j] < initial[j + 1];
          break;
        }
      }
      if (!good) continue;
    }
    long long sum = 0;
    bool ok = 1;
    long long cur = pos[i];
    cerr << "testing " << i << " " << initial[i] << endl;
    while (cur != -1) {
      sum++;
      cerr << cur << " " << parent[cur].first << " " << parent[cur].second
           << endl;
      if (cur == 0 || taken[parent[cur].first]) break;
      if (parent[cur].second) {
        ok = 0;
        break;
      }
      cur = parent[cur].first;
    }
    if (ok and k >= sum) {
      cerr << initial[i] << " was ok with sum of " << sum << " and k is " << k
           << endl;
      long long cur = pos[i];
      while (cur != -1) {
        taken[cur] = 1;
        cur = parent[cur].first;
      }
      k -= sum;
    }
  }
  string res = "";
  for (int i = 0; i < int(initial.size()); ++i) {
    res += initial[i];
    if (taken[pos[i]]) {
      res += initial[i];
    }
  }
  cout << res << endl;
  return 0;
}
