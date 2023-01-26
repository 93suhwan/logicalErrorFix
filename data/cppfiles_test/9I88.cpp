#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m, k;
   cin >> n >> m >> k;
   vector a(n, vector(m, 0LL));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
      }
   }
   while (k--) {
      int r;
      cin >> r;
      --r;
      int x = 0, y = r;
      while (x != n - 1) {
         if (a[x][y] == 1) {
            a[x][y] = 2;
            ++y;
         } else if (a[x][y] == 2) {
            ++x;
         } else {
            a[x][y] = 2;
            --y;
         }
      }
      cout << y + 1 << ' ';
   }
   return 0;
}