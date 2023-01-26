#include <bits/stdc++.h>
using namespace std;
long long N, Left, Right, Value;
long long seg[2000001], lazy[2000001], sparse[200001][20], First[200001],
    Last[200001], A[200001], depth[200001], dist[200001];
vector<long long> adj[200001];
void Spread(long long l, long long r, long long ind) {
  if (l != r) {
    lazy[ind * 2] += lazy[ind];
    seg[ind * 2] += lazy[ind];
    lazy[ind * 2 + 1] += lazy[ind];
    seg[ind * 2 + 1] += lazy[ind];
  }
  lazy[ind] = 0;
}
long long Query(long long l = 1, long long r = N, long long ind = 1) {
  if (l > Right || r < Left) return 0;
  Spread(l, r, ind);
  if (l >= Left and r <= Right) return seg[ind];
  long long mid = (l + r) / 2;
  return Query(l, mid, ind * 2) + Query(mid + 1, r, ind * 2 + 1);
}
void Update(long long l = 1, long long r = N, long long ind = 1) {
  if (l > Right || r < Left) return;
  Spread(l, r, ind);
  if (l >= Left and r <= Right) {
    lazy[ind] += Value;
    seg[ind] += Value;
    return;
  }
  long long mid = (l + r) / 2;
  Update(l, mid, ind * 2);
  Update(mid + 1, r, ind * 2 + 1);
  seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
}
long long pos(long long x) {
  Left = Right = First[x];
  return Query();
}
long long ind = 1;
void dfs(long long cur = 1, long long par = 0, long long dep = 0) {
  sparse[cur][0] = par;
  depth[cur] = dep;
  First[cur] = ind++;
  if (cur != 1) dist[cur] = dist[par] + A[cur] + A[par];
  for (long long i = 1; (1 << i) <= dep; i++) {
    sparse[cur][i] = sparse[sparse[cur][i - 1]][i - 1];
  }
  for (long long i : adj[cur]) {
    if (i != par) {
      dfs(i, cur, dep + 1);
    }
  }
  Last[cur] = ind - 1;
}
long long kth(long long a, long long k) {
  for (long long i = 19; i >= 0; i--) {
    if (k & (1 << i)) a = sparse[a][i];
  }
  return a;
}
long long lca(long long a, long long b) {
  if (depth[b] > depth[a]) swap(a, b);
  long long d = depth[a] - depth[b];
  a = kth(a, d);
  if (a == b) return a;
  for (long long i = 19; i >= 0; i--) {
    if (sparse[a][i] != sparse[b][i]) {
      a = sparse[a][i];
      b = sparse[b][i];
    }
  }
  return sparse[a][0];
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, q;
  cin >> n >> q;
  N = exp2(ceil(log2(n)));
  for (long long i = 1; i <= n; i++) {
    cin >> A[i];
    A[i] = abs(A[i]);
  }
  for (long long i = 1; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs();
  for (long long i = 1; i <= n; i++) {
    seg[N + First[i] - 1] = dist[i];
  }
  while (q--) {
    long long t, a, b;
    cin >> t >> a >> b;
    if (--t) {
      cout << pos(a) + pos(b) - 2 * pos(lca(a, b)) << '\n';
    } else {
      b = abs(b);
      if (a != 1) {
        Left = Right = First[a];
        Value = -A[a] + b;
        Update();
        Left = First[a] + 1;
        Right = Last[a];
        Value = 2 * (-A[a] + b);
        Update();
      } else {
        Left = First[a] + 1;
        Right = Last[a];
        Value = (-A[a] + b);
        Update();
      }
      A[a] = b;
    }
  }
}
