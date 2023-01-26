#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
long long powMod(long long x, long long y) {
  long long p = 1;
  while (y) {
    if (y % 2) {
      p = (p * (x % ((long long)1e9 + 7))) % ((long long)1e9 + 7);
    }
    y /= 2;
    x = ((x % ((long long)1e9 + 7)) * (x % ((long long)1e9 + 7))) %
        ((long long)1e9 + 7);
  }
  return p;
}
long long CpowMod(long long x, long long y, long long w) {
  long long p = 1;
  while (y) {
    if (y % 2) {
      p = (p * (x % w)) % w;
    }
    y /= 2;
    x = ((x % w) * (x % w)) % w;
  }
  return p;
}
long long invMod(long long x) { return powMod(x, ((long long)1e9 + 7) - 2); }
long long CinvMod(long long x, long long w) { return CpowMod(x, w - 2, w); }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long totLeaf;
vector<set<long long> > edges;
long long bud = -1;
long long n;
void removeEdge(long long x, long long y) {
  {};
  edges[x].erase(y);
}
void dfs(long long node, long long par) {
  for (auto &it : edges[node]) {
    if (it != par) {
      dfs(it, node);
    }
  }
  long long cnt = 0;
  for (auto &it : edges[node]) {
    if (it == par || edges[it].count(node) == 0) {
      continue;
    }
    cnt++;
  }
  if (cnt) {
    totLeaf += cnt;
    bud++;
    removeEdge(node, par);
  }
}
void solve() {
  long long T;
  cin >> T;
  while (T--) {
    totLeaf = 0;
    bud = -1;
    cin >> n;
    edges = vector<set<long long> >(n + 1);
    for (long long i = 0; i <= n - 2; i++) {
      long long x, y;
      cin >> x >> y;
      edges[x].insert(y);
      edges[y].insert(x);
    }
    dfs(1, 0);
    cout << totLeaf - (bud) << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  solve();
  return 0;
}
