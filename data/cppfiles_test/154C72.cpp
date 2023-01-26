#include <bits/stdc++.h>
using namespace std;
long long int ar[500009], cr[500009], br[500009], vis[500009], dr[500009],
    fact[500009];
map<long long int, long long int> mp, mp1;
vector<long long int> v, v1;
string s, q;
long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int a, b, c, d, e, i, j, k = 0, x, y, z, f, g, h, n, m, t, r;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    ar[1] = a;
    ar[2] = b;
    ar[3] = c;
    sort(ar + 1, ar + 3 + 1);
    k = 0;
    if (ar[3] == (ar[1] + ar[2])) {
      k = 1;
    }
    if (ar[1] == ar[2] and ar[3] % 2 == 0) {
      k = 1;
    }
    if (ar[1] == ar[3] and ar[2] % 2 == 0) {
      k = 1;
    }
    if (ar[3] == ar[2] and ar[1] % 2 == 0) {
      k = 1;
    }
    if (k == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
