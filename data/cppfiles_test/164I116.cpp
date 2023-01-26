#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int M = 4e5 + 1;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long INF = 1e17;
const int inf = 1e9;
long long n, m, k;
string s;
vector<int> l(n + 1), r(n + 1);
vector<char> val(n + 1);
vector<int> pos(n + 1);
vector<bool> dup(n + 1), good(n + 1);
string dfs1(int node, int len) {
  if (node == 0) return "";
  string before = dfs1(l[node], len);
  pos[before.length() + len] = node;
  return before + val[node] + dfs1(r[node], len + before.size() + 1);
}
void dfs2(int node, int depth) {
  if (depth > k || node == 0) return;
  dfs2(l[node], depth + 1);
  if (dup[l[node]])
    dup[node] = true;
  else if (good[node]) {
    dup[node] = true;
    k -= depth;
  }
  if (dup[node]) {
    dfs2(r[node], 1);
  }
}
void solve() {
  cin >> n >> k;
  l.clear();
  r.clear();
  val.clear();
  pos.clear();
  dup.clear();
  good.clear();
  l.resize(n + 1);
  r.resize(n + 1);
  val.resize(n + 1);
  pos.resize(n + 1);
  dup.resize(n + 1);
  good.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    val[i] = c;
  }
  for (int i = 1; i <= n; i++) {
    int l1, r1;
    cin >> l1 >> r1;
    l[i] = l1;
    r[i] = r1;
  }
  s = dfs1(1, 0);
  for (int i = 0; i < n - 1; i++) {
    if (val[pos[i]] <= val[pos[i + 1]]) {
      good[pos[i]] = true;
    }
  }
  dfs2(1, 1);
  for (int i = 0; i < n; i++) {
    cout << val[pos[i]];
    if (dup[pos[i]]) {
      cout << val[pos[i]];
    }
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
