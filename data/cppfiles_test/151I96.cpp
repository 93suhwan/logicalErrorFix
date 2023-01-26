#include <bits/stdc++.h>
const int N = 5e5;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
int par[N + 5];
void init() {
  for (long long int i = 1; i <= N; i++) par[i] = i;
}
int get(int n) {
  if (par[n] == n) return n;
  return par[n] = get(par[n]);
}
void uni(int a, int b) { par[a] = b; }
int v[500005];
int in[500005];
void solve() {
  init();
  long long int nw = 1e5;
  long long int q;
  long long int i = 1;
  cin >> q;
  int x, y;
  while (q--) {
    long long int t;
    cin >> t;
    if (t == 1) {
      cin >> x;
      v[i] = x;
      if (in[x]) {
        uni(get(in[x]), i);
      } else {
        in[x] = i;
      }
      i++;
    } else {
      cin >> x >> y;
      int xin = in[x];
      if (xin == 0) continue;
      long long int yin = in[y];
      yin = get(yin);
      if (yin == 0) {
        yin = xin;
        v[yin] = y;
        in[y] = yin;
        in[x] = 0;
      } else {
        if (get(in[x]) == get(in[y])) continue;
        uni(get(in[x]), get(in[y]));
        in[x] = 0;
      }
    }
  }
  for (long long int j = 1; j <= i - 1; j++) {
    x = get(j);
    cout << v[x] << ' ';
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
