#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int st[N];
void solve() {
  int n, m, q;
  cin >> n >> m;
  memset(st, 0, sizeof st);
  int tot = 0;
  while (m--) {
    int a, b;
    cin >> a >> b;
    int t = min(a, b);
    st[t]++;
    if (st[t] == 1) tot++;
  }
  cin >> q;
  while (q--) {
    int op, a, b;
    cin >> op;
    if (op == 3) {
      cout << n - tot << '\n';
    } else {
      cin >> a >> b;
      if (op == 1) {
        int t = min(a, b);
        st[t]++;
        if (st[t] == 1) tot++;
      } else {
        int t = min(a, b);
        st[t]--;
        if (st[t] == 0) tot--;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
