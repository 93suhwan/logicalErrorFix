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
vector<vector<long long>> jump(30, vector<long long>(1e6));
long long nearest_taken(vector<bool> &taken, long long cur) {
  if (taken[cur]) return 0;
  long long sum = 0;
  for (int i = 0; i < int(30); ++i) {
    if (!taken[jump[i][cur]]) {
      sum += 1 << i;
      cur = jump[i][cur];
    }
  }
  return sum + 1;
}
long long dist_to_root(long long cur, long long root) {
  long long ans = 0;
  if (cur == root) return 1;
  for (int i = 0; i < int(30); ++i) {
    if (jump[i][cur] != root) {
      ans += 1 << i;
      cur = jump[i][cur];
    }
  }
  return ans + 2;
}
vector<pair<long long, long long>> parent(1e6);
long long dist(vector<bool> &taken, long long cur) {
  if (jump[29][cur] != 0) {
    if (taken[parent[jump[29][cur]].first])
      return dist_to_root(cur, jump[29][cur]);
    return inf;
  }
  return min(nearest_taken(taken, cur), dist_to_root(cur, 0));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<pair<long long, long long>> g(n);
  parent[0] = make_pair(0, 0);
  for (int i = 0; i < int(n); ++i) {
    long long a, b;
    cin >> a >> b;
    a--, b--;
    g[i] = make_pair(a, b);
    if (a != -1) parent[a] = make_pair(i, 0);
    if (b != -1) parent[b] = make_pair(i, 1);
  }
  for (int i = 0; i < int(n); ++i)
    jump[0][i] = parent[i].second ? i : parent[i].first;
  for (int i = 1; i < int(30); ++i)
    for (int j = 0; j < int(n); ++j) jump[i][j] = jump[i - 1][jump[i - 1][j]];
  for (int i = 0; i < int(3); ++i) {
    cerr << "i: " << i << endl;
    for (int a = 0; a < int(n); ++a) cerr << jump[i][a] << " ";
    cerr << endl;
  }
  string initial = f(0, g, s);
  vector<bool> taken(n);
  vector<long long> suffix(n + 1);
  suffix[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (initial[i] == initial[i + 1])
      suffix[i] = suffix[i + 1];
    else
      suffix[i] = initial[i + 1];
  }
  cerr << initial << endl;
  for (int i = 0; i < int(initial.size() - 1); ++i) {
    if (initial[i] > initial[i + 1])
      continue;
    else if (initial[i] == initial[i + 1] and suffix[i] <= initial[i]) {
      continue;
    }
    long long cur = pos[i];
    if (dist(taken, cur) <= k) {
      cerr << "took " << initial[i] << " " << i << " " << dist(taken, cur)
           << endl;
      k -= dist(taken, cur);
      while (cur) {
        taken[cur] = 1;
        cur = parent[cur].first;
      }
      taken[0] = 1;
    } else
      cerr << "didin't take " << initial[i] << " " << i << " "
           << dist(taken, cur) << " becuase k was " << k << endl;
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
