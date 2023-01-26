#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return l + rng() % (r - l + 1); }
const int N = 1e5 + 100;
int n, q;
const int T = 400;
int jump[N];
int p[N], r[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) r[p[i]] = i;
  for (int i = 1; i <= n; i++) {
    int x = i;
    for (int j = 1; j <= T; j++) x = p[x];
    jump[i] = x;
  }
  while (q--) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int x, y;
      cin >> x >> y;
      swap(r[p[x]], r[p[y]]);
      swap(p[x], p[y]);
      for (int _ = 0; _ <= 1; _++) {
        int tmp = x;
        for (int i = 1; i <= T; i++) {
          tmp = jump[tmp];
        }
        for (int i = 1; i <= T; i++) {
          jump[x] = tmp;
          x = r[x];
          tmp = r[tmp];
        }
        swap(x, y);
      }
    } else {
      int id, k;
      cin >> id >> k;
      while (k >= T) {
        id = jump[id];
        k -= T;
      }
      while (k--) id = p[id];
      cout << id << "\n";
    }
  }
}
