#include <bits/stdc++.h>
using namespace std;
long long int ar[500009], cr[500009], br[1000009], tr[500009], dr[500009],
    fact[500009];
map<long long int, long long int> mp, mp1, mp2;
vector<long long int> v, v1;
string s[500009], q, p;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int a, b, c, d, e, i, j, k = 0, x, y, z, f, g, h, n, m, t, r,
                                     mod = 998244353;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 3; i <= n; i++) {
      cin >> s[i];
    }
    q = "";
    q += s[3];
    k = 1;
    for (i = 4; i <= n; i++) {
      if (q[k] == s[i][0]) {
      } else {
        q += s[i][0];
        k++;
      }
      q += s[i][1];
      k++;
    }
    y = q.size();
    for (i = y + 1; i <= n; i++) {
      q += 'a';
    }
    cout << q << endl;
  }
}
