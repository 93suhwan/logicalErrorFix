#include <bits/stdc++.h>
using namespace std;
int const M = 300005;
long long n, q, ans, x, y, kl[M], z, m;
set<long long> st[M];
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y;
    z = min(x, y);
    st[x].insert(y);
    st[y].insert(x);
    if (!kl[z]) {
      kl[z] = 1;
      ++ans;
    }
  }
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      z = min(x, y);
      st[x].insert(y);
      st[y].insert(x);
      if (!kl[z]) {
        kl[z] = 1;
        ++ans;
      }
    } else if (op == 2) {
      cin >> x >> y;
      z = min(x, y);
      st[x].erase(y);
      st[y].erase(x);
      if (st[z].size() > 0) {
        auto it = st[z].end();
        --it;
        if (*it < z) {
          kl[z] = 0;
          --ans;
        }
      } else {
        kl[z] = 0;
        --ans;
      }
    } else
      cout << n - ans << endl;
  }
}
