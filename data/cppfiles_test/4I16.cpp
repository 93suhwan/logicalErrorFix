#include <bits/stdc++.h>
using namespace std;
long long res;
int N, K;
int A[200201];
vector<pair<int, int> > g[200201];
int sz[200201];
bool vis[200201];
long long fenC[200201], fenH[200201], fenCC[200201], fenHH[200201];
long long Sum(long long fen[], int idx) {
  idx++;
  idx = min(idx, N);
  if (idx < 0) return 0LL;
  long long ret = 0;
  while (idx) {
    ret += fen[idx], ret %= 1000000007;
    idx &= idx - 1;
  }
  return ret;
}
void Add(long long fen[], int idx, long long val) {
  idx++;
  while (idx <= N) {
    fen[idx] += val, fen[idx] %= 1000000007;
    idx += idx & -idx;
  }
}
void Del(long long fen[], int idx) {
  idx++;
  while (idx <= N) {
    fen[idx] = 0;
    idx += idx & -idx;
  }
}
void DFS(int n, int prev) {
  sz[n] = 1;
  for (auto [next, cost] : g[n]) {
    if (next == prev || vis[next]) continue;
    DFS(next, n);
    sz[n] += sz[next];
  }
}
int Centroid(int n, int prev, const int V) {
  for (auto [next, cost] : g[n]) {
    if (next == prev || vis[next]) continue;
    if (sz[next] * 2 > V) return Centroid(next, n, V);
  }
  return n;
}
vector<pair<int, long long> > v;
void DFS2(int n, int prev, int last, int d, long long h, int root) {
  if (d <= K) {
    res += h + A[root], res %= 1000000007;
  }
  v.push_back({d, h % 1000000007});
  for (auto [next, cost] : g[n]) {
    if (next == prev || vis[next]) continue;
    DFS2(next, n, cost, d + (cost != last), h + A[next], root);
  }
}
void dnc(int n) {
  vis[n] = true;
  res += A[n], res %= 1000000007;
  vector<int> del;
  for (auto [next, cost] : g[n]) {
    if (vis[next]) continue;
    if (cost == 1) continue;
    v.clear();
    DFS2(next, n, cost, 0, A[next], n);
    for (auto [d, h] : v) {
      long long cnt = Sum(fenC, K - d), val = Sum(fenH, K - d);
      res += (h + A[n]) * cnt + val, res %= 1000000007;
      Add(fenC, d, 1), Add(fenH, d, h);
      del.push_back(d);
    }
  }
  for (auto [next, cost] : g[n]) {
    if (vis[next]) continue;
    if (cost == 0) continue;
    v.clear();
    DFS2(next, n, cost, 0, A[next], n);
    for (auto [d, h] : v) {
      long long cnt = Sum(fenCC, K - d), val = Sum(fenHH, K - d);
      res += (h + A[n]) * cnt + val, res %= 1000000007;
      Add(fenCC, d, 1), Add(fenHH, d, h);
      cnt = Sum(fenC, K - d - 1), val = Sum(fenH, K - d - 1);
      res += (h + A[n]) * cnt + val, res %= 1000000007;
      del.push_back(d);
    }
  }
  for (int d : del) {
    Del(fenC, d);
    Del(fenH, d);
    Del(fenCC, d);
    Del(fenHH, d);
  }
  for (auto [next, cost] : g[n]) {
    if (vis[next]) continue;
    DFS(next, n);
    dnc(Centroid(next, n, sz[next]));
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 0; i < N - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  DFS(1, 0);
  dnc(Centroid(1, 0, N));
  res %= 1000000007;
  res += 1000000007;
  res %= 1000000007;
  cout << res << "\n";
  return 0;
}
