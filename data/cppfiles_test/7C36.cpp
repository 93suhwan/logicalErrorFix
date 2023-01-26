#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const int INF = 1e9 + 10;
template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;
struct Trie {
  struct Node {
    int son[2] = {-1, -1};
    int x = -1;
  };
  vector<Node> a;
  void Init(int init_cap = 0) {
    a.clear();
    a.emplace_back();
    a.reserve(init_cap + 1);
  }
  void Add(const vector<int>& s, int x) {
    int p = 0;
    for (auto& x : (s)) {
      if (a[p].son[x] < 0) {
        a[p].son[x] = int((a).size());
        a.emplace_back();
      }
      p = a[p].son[x];
    }
    a[p].x = x;
  }
};
char a[505], b[505];
int na, nb;
int nxt[505][2];
void Solve() {
  scanf("%d%d", &na, &nb);
  scanf("%s", a);
  scanf("%s", b);
  Trie tr;
  tr.Init(nb * nb);
  vector<int> tmp;
  for (int i = 0; i <= nb; ++i) {
    tmp.clear();
    for (int j = i - 1; j >= 0; --j) tmp.push_back(b[j] - '0');
    tr.Add(tmp, i);
  }
  tmp.resize(nb + 1);
  for (int i = 0; i <= nb; ++i) {
    for (int c = 0; c <= 1; ++c) {
      tmp[i] = c;
      int p = 0;
      int max_len = 0;
      for (int j = i; j >= 0; --j) {
        if (tr.a[p].son[tmp[j]] < 0) break;
        p = tr.a[p].son[tmp[j]];
        if (tr.a[p].x >= 0) max_len = tr.a[p].x;
      }
      nxt[i][c] = max_len;
    }
    42;
    tmp[i] = b[i] - '0';
  }
  int t = na - nb + 1;
  vector<vector<int>> cur;
  cur.push_back({0});
  for (int i = 0; i < na; ++i) {
    auto pre = move(cur);
    cur.clear();
    for (int j = 0; j <= t && j < int((pre).size()); ++j) {
      for (int k = 0; k < int((pre[j]).size()); ++k) {
        int w = pre[j][k];
        if (w == INF) continue;
        for (int d = 0; d <= 1; ++d) {
          int prefix_len = nxt[k][d];
          int w2 = w + (d != a[i] - '0');
          int j2 = j;
          if (prefix_len == nb) {
            ++j2;
          }
          if (j2 >= int((cur).size())) cur.resize(j2 + 1, {});
          if (prefix_len >= int((cur[j2]).size())) {
            cur[j2].resize(prefix_len + 1, INF);
          }
          cur[j2][prefix_len] = min(cur[j2][prefix_len], w2);
        }
      }
    }
  }
  for (int i = 0; i <= t; ++i) {
    int res = INF;
    if (i < int((cur).size())) {
      for (int j = 0; j < int((cur[i]).size()); ++j) res = min(res, cur[i][j]);
    }
    if (res == INF) res = -1;
    printf("%d ", res);
  }
  printf("\n");
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
  return 0;
}
