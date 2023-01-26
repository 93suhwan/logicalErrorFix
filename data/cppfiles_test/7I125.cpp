#include "bits/stdc++.h"
using namespace std;
#define int long long
struct range_static_query {
  int **f, *a;
  int max_lv, n;
  int comp(int l, int r) { 
    return __gcd(l, r);
  }
  range_static_query(int _, vector<int> init) { // 1 indexed
    n = _; 
    max_lv = log2(n); 
    f = new int*[n + 1]; 
    a = new int[n + 1];
    for (int i = 1; i <= n; i ++) { 
      a[i] = init[i]; 
      f[i] = new int[max_lv + 1]; 
      f[i][0] = a[i]; 
    }
    for (int lv = 1; lv <= max_lv; lv ++) 
      for (int i = 1; i + (1 << lv) - 1 <= n; i ++) 
        f[i][lv] = comp(f[i][lv - 1], f[i + (1 << (lv - 1))][lv - 1]);
  }
  int query(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return comp(f[l][k], f[r - (1 << k) + 1][k]);
  }
};
void solution() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &u : a) cin >> u;
  vector<int> tmp;
  tmp.push_back(0);
  for (int i = 0; i + 1 < n; i ++) tmp.push_back(abs(a[i] - a[i + 1]));
  range_static_query d(n - 1, tmp);
  int best = 1;
  for (int i = 1; i < n; i ++) {
    int l = i + 1, r = n - 1, ans = i, m;
    while (l <= r) {
      m = (l + r) / 2;
      if (d.query(i, m) > 1) ans = m, l = m + 1;
      else r = m - 1;
    }
    best = max(best, 2 + ans - i);
  }
  cout << best;
}
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc = 1;
#ifdef DEBUG
  freopen("input.txt", "r", stdin); 
#endif
  cin >> tc; 
  while (tc --) { solution(); cout << "\n"; }
}
    