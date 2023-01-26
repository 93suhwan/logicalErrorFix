#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
struct q {
  int a, b, c;
};
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int _ = (0), __len = (t); _ < __len; ++_) {
    int n, m;
    cin >> n >> m;
    vector<q> qry(m);
    vector<bool> b(n);
    for (auto &e : qry) {
      cin >> e.a >> e.b >> e.c;
      --e.a;
      --e.b;
      --e.c;
      b[e.b] = true;
    }
    int center = 0;
    for (int i = (0), i_len = (n); i < i_len; ++i)
      if (!b[i]) center = i;
    for (int i = (0), i_len = (n); i < i_len; ++i) {
      if (i == center) continue;
      cout << center + 1 << ' ' << i + 1 << '\n';
    }
  }
  return 0;
}
