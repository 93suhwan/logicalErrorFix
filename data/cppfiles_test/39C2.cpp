#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
inline void debugMode() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<int> v[N], ans;
void dfs(int p, int par, int val = 1) {
  ans[p] = val;
  for (auto &it : v[p])
    if (it != par) dfs(it, p, val + 1);
}
int main() {
  int n;
  cin >> n;
  ans.resize(n + 1);
  int root = 0;
  for (int i = 1; i <= n; i++) {
    cout << "? ";
    for (int j = 1; j < i; j++) cout << 2 << ' ';
    cout << 1 << ' ';
    for (int j = i + 1; j <= n; j++) cout << 2 << ' ';
    cout << endl;
    int x;
    cin >> x;
    if (x == 0)
      root = i;
    else if (x != i) {
      v[x].push_back(i);
      v[i].push_back(x);
    }
    cout << "? ";
    for (int j = 1; j < i; j++) cout << 1 << ' ';
    cout << 2 << ' ';
    for (int j = i + 1; j <= n; j++) cout << 1 << ' ';
    cout << endl;
    cin >> x;
    if (x == 0)
      continue;
    else if (x != i) {
      v[x].push_back(i);
      v[i].push_back(x);
    }
  }
  dfs(root, -1);
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
