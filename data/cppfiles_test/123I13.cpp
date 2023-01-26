#include <bits/stdc++.h>
using namespace std;
const int SZ = 1 << 18;
vector<int> adj[200000];
int node_cnt, num[200000], rev[200000], parent[200000], R[200000], tree[2 * SZ],
    lazy[2 * SZ];
bool chk[200000];
void lazy_propagation(int bit, int s, int e) {
  tree[bit] += lazy[bit];
  if (s < e) {
    lazy[2 * bit] += lazy[bit];
    lazy[2 * bit + 1] += lazy[bit];
  }
  lazy[bit] = 0;
}
void add_tree(int n1, int n2, int v, int bit = 1, int s = 0, int e = SZ - 1) {
  int m = (s + e) >> 1;
  lazy_propagation(bit, s, e);
  if (n2 < n1 || n2 < s || e < n1) return;
  if (n1 <= s && e <= n2) {
    lazy[bit] = v;
    lazy_propagation(bit, s, e);
    return;
  }
  add_tree(n1, n2, v, 2 * bit, s, m);
  add_tree(n1, n2, v, 2 * bit + 1, m + 1, e);
  tree[bit] = max(tree[2 * bit], tree[2 * bit + 1]);
}
int get_pos(int bit = 1, int s = 0, int e = SZ - 1) {
  int m = (s + e) >> 1;
  lazy_propagation(bit, s, e);
  if (s == e) return m;
  if (tree[2 * bit] + lazy[2 * bit] == tree[bit]) return get_pos(2 * bit, s, m);
  return get_pos(2 * bit + 1, m + 1, e);
}
void dfs(int c) {
  num[c] = node_cnt++;
  rev[num[c]] = c;
  for (auto n : adj[c])
    if (num[n] == -1) {
      parent[n] = c;
      dfs(n);
    }
  R[c] = node_cnt - 1;
  add_tree(num[c], R[c], 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  ((void)0);
  int N, K;
  long long ans = 0x7fffffffffffffffLL;
  vector<int> V;
  cin >> N >> K;
  for (int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    adj[--a].push_back(--b);
    adj[b].push_back(a);
    num[i] = -1;
  }
  dfs(0);
  while (tree[1]) {
    int c = rev[get_pos()];
    V.push_back(tree[1]);
    for (; !chk[c]; c = parent[c]) {
      chk[c] = true;
      add_tree(num[c], R[c], -1);
    }
  }
  if (V.size() <= K) {
    cout << 1LL * N / 2 * (N - N / 2) << '\n';
    return 0;
  }
  for (int i = 1; i < V.size(); i++) V[i] += V[i - 1];
  for (int i = N - V[K - 1]; i >= 0; i--)
    ans = min(ans, 1LL * (N - K - i) * (K - i));
  cout << ans << '\n';
  return 0;
}
