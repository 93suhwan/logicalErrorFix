#include <bits/stdc++.h>
using namespace std;
long long x[1000001], y[1000001], h, d, xx, yy, z, zz, g, aa, bb, vis[1000001],
    mod = 998244353, inf = 1e18;
long long T, i, j, ii, jj, n, m, mm, a, b, c, k, r, l, q;
vector<long long> v[1000001], vv;
vector<pair<long long, long long> > vvv;
pair<long long, long long> p[1000001];
map<long long, long long> mp, mpp;
set<long long> se, st;
set<pair<long long, long long> >::iterator it, itt, it1;
string s, t, s2, s1, tt;
char cc;
int main() {
  ios::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> n >> s;
    z = 0;
    for (i = 0; i < n - 1; i++) {
      if (s[i] > '0') z += s[i] - '0' + 1;
    }
    z += s[i] - '0';
    cout << z;
    cout << endl;
  }
  return 0;
}
