#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b;
  node(int a = 0, int b = 1e9) : a(a), b(b) {}
  int get(int x) { return a * x + b; }
};
struct Eins {
  vector<node> st;
  int n;
  Eins(int n) : n(n) { st.resize(n << 2 | 1); }
  void modify(int id, int l, int r, node v) {
    int mid = l + r >> 1;
    if (st[id].get(mid) > v.get(mid)) {
      swap(st[id], v);
    }
    if (l == r) return;
    if (st[id].get(l) > v.get(l)) modify(id << 1, l, mid, v);
    if (st[id].get(r) > v.get(r)) modify(id << 1 | 1, mid + 1, r, v);
  }
  int get(int id, int l, int r, int x) {
    int ans = st[id].get(x);
    if (l == r) return ans;
    int mid = l + r >> 1;
    if (x <= mid) return min(ans, get(id << 1, l, mid, x));
    return min(ans, get(id << 1 | 1, mid + 1, r, x));
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n + 1);
  vector<Eins> Tree(m + 1, Eins(n + 1));
  auto sqr = [&](int x) { return x * x; };
  for (int i = 0; i <= n; i++) {
    cin >> s[i];
    int last = -1;
    for (int j = 0; j <= m; j++) {
      if (s[i][j] == '1') {
        if (last == -1) {
          for (int p = 0; p <= j; p++) {
            Tree[p].modify(1, 0, n, node(-2 * i, sqr(i) + sqr(p - j)));
          }
        } else {
          for (int p = last + 1; p <= j; p++) {
            Tree[p].modify(
                1, 0, n, node(-2 * i, sqr(i) + min(sqr(p - j), sqr(last - p))));
          }
        }
        last = j;
      } else if (j == m && last != -1) {
        for (int p = last + 1; p <= m; p++) {
          Tree[p].modify(1, 0, n, node(-2 * i, sqr(i) + sqr(p - last)));
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      ans += Tree[j].get(1, 0, n, i) + sqr(i);
    }
  }
  cout << ans;
}
