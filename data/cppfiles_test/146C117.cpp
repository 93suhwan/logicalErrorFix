#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int n, q;
int l[N], r[N], ans_sqrt[N];
int Q = 100;
void solve() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &r[i]);
    l[r[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    int p = i;
    for (int j = 0; j < Q; j++) {
      p = r[p];
    }
    ans_sqrt[i] = p;
  }
  while (q--) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      swap(r[x], r[y]);
      swap(l[r[x]], l[r[y]]);
      vector<int> vv;
      int pp = x;
      for (int p = 0; p < Q; p++) {
        pp = r[pp];
        vv.push_back(pp);
      }
      while (!vv.empty()) {
        ans_sqrt[x] = vv.back();
        vv.pop_back();
        x = l[x];
      }
      pp = y;
      for (int p = 0; p < Q; p++) {
        pp = r[pp];
        vv.push_back(pp);
      }
      while (!vv.empty()) {
        ans_sqrt[y] = vv.back();
        vv.pop_back();
        y = l[y];
      }
    } else {
      int ans = x;
      while (y >= Q) {
        y -= Q;
        ans = ans_sqrt[ans];
      }
      while (y--) {
        ans = r[ans];
      }
      printf("%d\n", ans);
    }
  }
}
int main() {
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
