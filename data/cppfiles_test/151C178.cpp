#include <bits/stdc++.h>
using namespace std;
vector<bool> isprime(1e6 + 6, true);
struct node {
  long long int val;
  long long int index;
};
void Sieve(long long int maxn) {
  long long int j;
  isprime[0] = isprime[1] = false;
  for (long long int i = 2; i < sqrt(maxn) + 1; i++) {
    if (isprime[i]) {
      for (j = i * i; j <= maxn; j += i) {
        isprime[j] = false;
      }
    }
  }
}
bool sortbysec(const pair<long long int, long long int> &c,
               const pair<long long int, long long int> &d) {
  if (c.second < d.second)
    return c.second < d.second;
  else
    return c.first < d.first;
}
vector<vector<long long int>> adj(3e6);
vector<bool> visited(1e6 + 1, false);
long long int modpow(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void dfs(long long int par, long long int v) {
  for (auto u : adj[v]) {
    if (u == par) continue;
    dfs(v, u);
  }
}
vector<bool> vis(1e6 + 1, false);
void bfs(long long int v, long long int par) {
  queue<int> q;
  q.push(v);
  vis[v] = true;
  while (!q.empty()) {
    long long int s = q.front();
    q.pop();
    for (auto x : adj[s]) {
      if (!vis[x]) {
        vis[x] = true;
        q.push(x);
      }
    }
  }
}
vector<long long int> link(1e6);
vector<long long int> sz(1e6);
long long int find(int a) {
  while (a != link[a]) {
    a = link[a];
  }
  return a;
}
void unite(long long int a, long long int b) {
  a = find(a);
  b = find(b);
  sz[b] += sz[a];
  sz[a] = 0;
  link[a] = b;
}
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, pair<long long int, long long int>>> q;
  long long int m = n;
  while (m--) {
    long long int a;
    cin >> a;
    if (a == 1) {
      long long int b;
      cin >> b;
      q.push_back(make_pair(1, make_pair(b, -1)));
    } else {
      long long int b, c;
      cin >> b >> c;
      q.push_back(make_pair(2, make_pair(b, c)));
    }
  }
  reverse(q.begin(), q.end());
  vector<long long int> ans;
  for (long long int i = 0; i < 1e6; i++) {
    link[i] = i;
    sz[i] = 1;
  }
  for (long long int i = 0; i < n; i++) {
    long long int a = q[i].first;
    pair<long long int, long long int> p = q[i].second;
    if (a == 1) {
      ans.push_back(link[p.first]);
    } else {
      link[p.first] = link[p.second];
    }
  }
  reverse(ans.begin(), ans.end());
  for (long long int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  solve();
}
