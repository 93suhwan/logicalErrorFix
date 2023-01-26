#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000")
using namespace std;
template <class T>
ostream &operator<<(ostream &out, vector<T> v) {
  bool first = true;
  for (auto &it : v) {
    out << (first ? "" : " ") << it;
    first = false;
  }
  return out;
}
template <class T>
ostream &operator<<(ostream &out, set<T> s) {
  bool first = true;
  for (auto &it : s) {
    out << (first ? "" : " ") << it;
    first = false;
  }
  return out;
}
template <class T, class Q>
ostream &operator<<(ostream &out, pair<T, Q> p) {
  out << p.first << " " << p.second;
  return out;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(vector<A> v) {
  string s = "{";
  if (!v.empty()) s += to_string(v.front());
  for (int(i) = (1); (i) < (v.size()); (i)++) s += " ," + to_string(v[i]);
  s += "}";
  return s;
}
void initiate() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
map<int, int> mp;
map<int, int> rmp;
map<int, int> ind;
int idx = 0;
vector<int> adj[10000000];
bool visited[10000000] = {false};
int node(int n) {
  if (mp.find(n) == mp.end()) {
    mp[n] = idx;
    rmp[idx] = n;
    idx++;
  }
  return mp[n];
}
void add(int n) {
  if (visited[node(n)]) return;
  visited[node(n)] = true;
  if (n == 0) return;
  for (int(i) = 0; (i) < (31); (i)++)
    if ((1 << i) >= n) {
      int nn = (1 << i) - n;
      if (nn != n) {
        adj[node(n)].push_back(node(nn));
        adj[node(nn)].push_back(node(n));
        add(nn);
      }
      return;
    }
}
int v1;
int maxi = 0;
void dfs(int u, int p, int dep) {
  if (dep > maxi && ind.find(rmp[u]) != ind.end()) {
    maxi = dep;
    v1 = u;
  }
  for (int(i) = 0; (i) < (adj[u].size()); (i)++) {
    int v = adj[u][i];
    if (v == p) continue;
    dfs(v, u, dep + 1);
  }
}
int main() {
  initiate();
  int n;
  cin >> n;
  for (int(i) = 0; (i) < (n); (i)++) {
    int k;
    cin >> k;
    add(k);
    ind[k] = i + 1;
  }
  dfs(0, -1, 0);
  int v2 = v1;
  maxi = 0;
  dfs(v2, -1, 0);
  cout << ind[rmp[v1]] << " " << ind[rmp[v2]] << " " << maxi << '\n';
}
