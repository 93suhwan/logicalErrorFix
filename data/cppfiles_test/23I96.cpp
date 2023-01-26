#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chkmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int Mod = 998244353;
int sum(int a, int b) { return (a + b >= Mod ? a + b - Mod : a + b); }
int mul(int a, int b) { return ((ll)a * b) % Mod; }
int powm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int inv(int a) { return powm(a, Mod - 2); }
int ans = 1;
const int M = 100228;
int type[M];
vector<int> go[M];
int tsz, root;
int color[M];
void init(int n) {
  if (n == 1) {
    root = tsz = 1;
  } else {
    root = tsz = n + 1;
    type[root] = 1;
    for (int i = 1; i <= n; i++) go[root].push_back(i);
  }
}
char *s;
void Paint(int u) {
  if (type[u] == 0) {
    color[u] = s[u] == '1' ? 2 : 1;
  } else {
    color[u] = 0;
    for (int v : go[u]) {
      Paint(v);
      color[u] |= color[v];
    }
  }
}
int Merge(vector<int> nodes) {
  if (nodes.empty()) return 0;
  if (nodes.size() == 1) return nodes[0];
  int node = ++tsz;
  type[node] = 1;
  go[node] = nodes;
  return node;
}
bool ok = true;
int Solve(int u, int t) {
  if (!ok) return 0;
  if (color[u] != 3) return u;
  vector<int> ch[3];
  for (int v : go[u]) ch[color[v] - 1].push_back(v);
  if (ch[2].size() > 2 || (t > 0 && ch[2].size() > 1)) {
    ok = false;
    return 0;
  }
  if (type[u] == 1) {
    if (t == 0) {
      go[u] = ch[0];
      if (ch[2].size() == 2 || (ch[2].size() > 0 && ch[1].size() > 0)) {
        int Q = Solve(ch[2][0], 1);
        if (!ok) return 0;
        int b = Merge(ch[1]);
        if (b) go[Q].push_back(b);
        if (ch[2].size() > 1) {
          int q = Solve(ch[2][1], 2);
          if (!ok) return 0;
          for (int v : go[q]) go[Q].push_back(v);
        }
        go[u].push_back(Q);
      } else if (ch[2].size() == 1) {
        int Q = Solve(ch[2][0], 0);
        if (!ok) return 0;
        go[u].push_back(Q);
      } else {
        int b = Merge(ch[1]);
        if (b) go[u].push_back(b);
      }
    } else {
      type[u] = 2;
      go[u].clear();
      int w = Merge(ch[0]);
      if (w) go[u].push_back(w);
      if (ch[2].size()) {
        int g = Solve(ch[2][0], 1);
        if (!ok) return 0;
        for (int v : go[g]) go[u].push_back(v);
      }
      int b = Merge(ch[1]);
      if (b) go[u].push_back(b);
      if (t == 2) reverse(go[u].begin(), go[u].end());
    }
    if (go[u].size() == 1) return go[u][0];
    return u;
  } else {
    string pattern = t == 0 ? "wgbgw" : "wgb";
    int ptr = 0;
    if (color[go[u][0]] == 2 || color[go[u].back()] == 1)
      reverse(go[u].begin(), go[u].end());
    vector<int> ngo;
    bool strict =
        t != 0 || ch[2].size() > 1 || (ch[2].size() > 0 && ch[1].size() > 0);
    for (int v : go[u]) {
      char col = color[v] == 1 ? 'w' : color[v] == 2 ? 'b' : 'g';
      while (ptr < pattern.size() && pattern[ptr] != col) ptr++;
      if (ptr == pattern.size()) {
        ok = false;
        return 0;
      }
      if (color[v] != 3) {
        ngo.push_back(v);
      } else {
        int Q;
        if (!strict)
          Q = Solve(v, 0);
        else if (ptr == 1)
          Q = Solve(v, 1);
        else
          Q = Solve(v, 2);
        if (!ok) return 0;
        if (type[Q] == 1)
          ngo.push_back(Q);
        else
          for (int h : go[Q]) ngo.push_back(h);
        ptr++;
      }
    }
    go[u] = ngo;
    if (t == 2) reverse(go[u].begin(), go[u].end());
    return u;
  }
}
void AddSet(char *t) {
  if (!ok) return;
  s = t;
  Paint(root);
  root = Solve(root, 0);
  if (root == 0) {
    cout << 0 << '\n';
    exit(0);
  }
}
void Print(int u) {
  if (type[u] == 0) {
    printf("%i ", u);
  } else {
    if (type[u] == 1) {
      printf("P{ ");
    } else
      printf("Q[ ");
    for (int v : go[u]) Print(v);
    if (type[u] == 1) {
      printf("} ");
    } else
      printf("] ");
  }
}
vector<int> ord;
int DFS(int u) {
  if (type[u] == 0) {
    ord.push_back(u);
    return 1;
  } else {
    int cnte = 0;
    for (int v : go[u]) {
      cnte += (DFS(v) > 0);
    }
    if (type[u] == 2) {
      ans = mul(ans, 2);
    } else {
      int cnt = 0;
      for (int v : go[u]) {
        cnt++;
        ans = mul(ans, cnt);
      }
    }
    return cnte;
  }
}
char mat[1005][1005];
int main() {
  int n;
  cin >> n;
  init(n);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int k;
    cin >> k;
    string s;
    for (int j = 0; j <= n; j++) {
      s += '0';
    }
    for (int j = 0; j < k; j++) {
      int id;
      cin >> id;
      s[id] = '1';
    }
    for (int j = 0; j <= n; j++) {
      mat[i][j] = s[j];
    }
    AddSet(mat[i]);
  }
  if (ok) {
    ans = 1;
    DFS(root);
    cout << ans << '\n';
  } else {
    cout << 0 << '\n';
  }
  return 0;
}
