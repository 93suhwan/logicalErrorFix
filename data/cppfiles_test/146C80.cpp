#include <bits/stdc++.h>
using namespace std;
void die(string S) {
  puts(S.c_str());
  exit(0);
}
const int B = 300;
int prv[100100], nxt[100100], nxtb[100100];
int Nxtb(int x) {
  for (int i = 0; i < B; i++) x = nxt[x];
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
    prv[nxt[i]] = i;
  }
  for (int i = 1; i <= n; i++) nxtb[i] = Nxtb(i);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      prv[nxt[x]] = y;
      prv[nxt[y]] = x;
      swap(nxt[x], nxt[y]);
      int px = Nxtb(x), py = Nxtb(y);
      for (int i = 0; i < B; i++) {
        nxtb[x] = px;
        nxtb[y] = py;
        x = prv[x];
        y = prv[y];
        px = prv[px];
        py = prv[py];
      }
    } else {
      int x, l;
      cin >> x >> l;
      for (int i = 0; i < l / B; i++) x = nxtb[x];
      for (int i = 0; i < l % B; i++) x = nxt[x];
      cout << x << endl;
    }
  }
  return 0;
}
