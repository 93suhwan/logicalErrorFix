#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long n, q;
long long sprasetable[100001][20];
struct node {
  long long value, lazy = 0, tag = true;
  node operator+(node b);
};
node node::operator+(node b) {
  node re;
  re.value = value + b.value;
  return re;
}
struct segtree {
  vector<long long> A = vector<long long>(200000 + 1, 0);
  vector<node> st = vector<node>(4 * 200000);
  void build(int l, int r, int id) {
    if (l == r) {
      st[id].value = A[l];
      st[id].tag = false;
    } else {
      int mid = (l + r) / 2;
      build(l, mid, id * 2);
      build(mid + 1, r, id * 2 + 1);
      st[id] = st[id * 2] + st[id * 2 + 1];
    }
  }
  void query1(int l, int r, int pos, int id, long long k) {
    if (l <= pos && r >= pos) {
      if (l == r)
        st[id].value += k;
      else {
        int mid = (l + r) / 2;
        query1(l, mid, pos, id * 2, k);
        query1(mid + 1, r, pos, id * 2 + 1, k);
        st[id] = st[id * 2] + st[id * 2 + 1];
      }
    }
  }
  long long query2(int l, int r, int ql, int qr, int id) {
    if (l > qr || r < ql)
      return 0;
    else if (l >= ql && r <= qr) {
      return st[id].value;
    } else {
      int mid = (l + r) / 2;
      return query2(l, mid, ql, qr, id * 2) +
             query2(mid + 1, r, ql, qr, id * 2 + 1);
    }
  }
};
struct hld {
  vector<vector<int>> graph;
  vector<int> chainhead;
  vector<int> heavy;
  vector<int> pos;
  vector<long long> A;
  vector<long long> val;
  vector<int> level;
  vector<int> subtreesize;
  segtree sus;
  void DFS(int x) {
    subtreesize[x] = 1;
    for (auto v : graph[x]) {
      if (!subtreesize[v]) {
        level[v] = level[x] + 1;
        sprasetable[v][0] = x;
        DFS(v);
        if (subtreesize[v] > subtreesize[heavy[x]]) {
          heavy[x] = v;
        }
        subtreesize[x] += subtreesize[v];
      }
    }
  }
  void HLD(int x) {
    if (!chainhead[x]) chainhead[x] = x;
    pos[x] = A.size();
    A.push_back(val[x]);
    if (!heavy[x])
      return;
    else {
      chainhead[heavy[x]] = chainhead[x];
      HLD(heavy[x]);
      for (auto v : graph[x]) {
        if (!chainhead[v]) HLD(v);
      }
    }
  }
  long long travelup(long long x, long long distance) {
    for (long long i = 0; i < 20; i++) {
      if (bool(distance & (1 << i))) x = sprasetable[x][i];
      if (x == -1) return -1;
    }
    return x;
  }
  long long LCA(long long a, long long b) {
    if (level[a] < level[b]) swap(a, b);
    long long distance = level[a] - level[b];
    a = travelup(a, distance);
    long long curr = 0;
    while (sprasetable[a][curr] != sprasetable[b][curr]) curr++;
    for (long long i = curr; i >= 0; i--) {
      if (sprasetable[a][i] != sprasetable[b][i]) {
        a = sprasetable[a][i];
        b = sprasetable[b][i];
      }
    }
    if (a == b)
      return a;
    else
      return sprasetable[a][0];
  }
  void build() {
    graph.resize(n + 1);
    subtreesize.assign(n + 1, 0);
    chainhead.assign(n + 1, 0);
    heavy.assign(n + 1, 0);
    pos.resize(n + 1, 0);
    level.resize(n + 1, 0);
    val.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> val[i];
      val[i] = abs(val[i]);
    }
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    DFS(1);
    HLD(1);
    sus.A = A;
    sus.build(0, n - 1, 1);
    sprasetable[1][0] = -1;
    for (long long x = 1; x < 20; x++) {
      for (long long i = 1; i <= n; i++) {
        if (sprasetable[i][x - 1] != -1)
          sprasetable[i][x] = sprasetable[sprasetable[i][x - 1]][x - 1];
        else
          sprasetable[i][x] = -1;
      }
    }
  }
  long long getuppath(long long u, long long a) {
    long long ans = 0, curr = u;
    while (curr != -1) {
      if (level[curr] < level[a]) break;
      if (level[chainhead[curr]] <= level[a]) {
        ans += sus.query2(0, n - 1, pos[chainhead[curr]], pos[curr], 1);
        curr = travelup(chainhead[curr], 1);
      } else {
        ans += sus.query2(0, n - 1, pos[a], pos[curr], 1);
        break;
      }
    }
    return ans;
  }
  long long query(long long u, long long v) {
    if (u == v) return 0;
    long long c = LCA(u, v);
    return 2 * (getuppath(u, c) + getuppath(v, c) - val[c]) - val[u] - val[v];
  }
  void update(long long u, long long k) {
    k -= val[u];
    val[u] += k;
    sus.query1(0, n - 1, pos[u], 1, k);
  }
};
int main() {
  cin >> n >> q;
  hld lol;
  lol.build();
  for (int i = 0; i < q; i++) {
    int x, a, b;
    cin >> x >> a >> b;
    if (x == 2)
      cout << lol.query(a, b) << endl;
    else {
      b = abs(b);
      lol.update(a, b);
    }
  }
}
