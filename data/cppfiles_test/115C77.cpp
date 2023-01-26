#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 1, -1, 0, -1, 1, -1};
int dy[] = {1, 0, 1, 0, -1, -1, -1, 1};
long long int fact[100010], fact_inv[100010];
long long int power(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int a = power(x, y / 2, m);
  if (y % 2) {
    return (a * ((a * x) % m)) % m;
  } else {
    return (a * a) % m;
  }
}
long long int mod_inverse(long long int x, long long int m) {
  return power(x, m - 2, m);
}
long long int ncr(long long int n, long long int r, long long int m) {
  if (r > n || r < 0) return 0;
  if (n < 0) return 0;
  long long int n1 = 1, d1 = 1, d2 = 1;
  n1 = fact[n];
  d1 = fact_inv[r];
  d2 = fact_inv[n - r];
  long long int ans = (d1 * d2) % m;
  ans = (ans * n1) % m;
  return ans;
}
void pre_compute() {
  int mx = 100001;
  fact[0] = 1ll;
  for (int i = 1; i <= mx; ++i) {
    fact[i] = (fact[i - 1] * ((long long int)i)) % 998244353ll;
  }
  for (int i = 0; i <= mx; ++i) {
    fact_inv[i] = mod_inverse(fact[i], 998244353ll);
  }
}
class solver {
 public:
  void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int cnt[2][3] = {};
    cnt[0][2] = n;
    cnt[1][2] = m;
    int cc[2] = {};
    map<int, int> mp[2][2][2];
    set<pair<int, int> > st1, st0;
    for (int t = 1; t <= k; ++t) {
      int x, y, fg;
      cin >> x >> y >> fg;
      pair<int, int> pr = {x, y};
      int tm = 0;
      if (mp[0][0][0][x] == 0 && mp[0][1][1][x] == 0) tm++;
      if (mp[0][0][1][x] == 0 && mp[0][1][0][x] == 0) tm++;
      cnt[0][tm]--;
      tm = 0;
      if (mp[1][0][0][y] == 0 && mp[1][1][1][y] == 0) tm++;
      if (mp[1][0][1][y] == 0 && mp[1][1][0][y] == 0) tm++;
      cnt[1][tm]--;
      if (st0.count(pr) != 0) {
        mp[0][0][y % 2][x]--;
        mp[1][0][x % 2][y]--;
        st0.erase(pr);
        if ((x + y) % 2 == 0)
          cc[0]--;
        else
          cc[1]--;
      } else if (st1.count(pr) != 0) {
        mp[0][1][y % 2][x]--;
        mp[1][1][x % 2][y]--;
        st1.erase(pr);
        if ((x + y) % 2 == 1)
          cc[0]--;
        else
          cc[1]--;
      }
      if (fg == 0) {
        mp[0][0][y % 2][x]++;
        mp[1][0][x % 2][y]++;
        st0.insert(pr);
        if ((x + y) % 2 == 0)
          cc[0]++;
        else
          cc[1]++;
      } else if (fg == 1) {
        mp[0][1][y % 2][x]++;
        mp[1][1][x % 2][y]++;
        st1.insert(pr);
        if ((x + y) % 2 == 1)
          cc[0]++;
        else
          cc[1]++;
      }
      tm = 0;
      if (mp[0][0][0][x] == 0 && mp[0][1][1][x] == 0) tm++;
      if (mp[0][0][1][x] == 0 && mp[0][1][0][x] == 0) tm++;
      cnt[0][tm]++;
      tm = 0;
      if (mp[1][0][0][y] == 0 && mp[1][1][1][y] == 0) tm++;
      if (mp[1][0][1][y] == 0 && mp[1][1][0][y] == 0) tm++;
      cnt[1][tm]++;
      long long int a1 = 0ll, a2 = 0ll;
      if (cnt[0][0] == 0) a1 = power(2ll, cnt[0][2], 998244353ll);
      if (cnt[1][0] == 0) a2 = power(2ll, cnt[1][2], 998244353ll);
      long long int ans = (a1 + a2) % 998244353ll;
      if (cc[0] == 0) ans--;
      if (cc[1] == 0) ans--;
      ans = (ans + 998244353ll) % 998244353ll;
      cout << ans << '\n';
    }
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  while (test--) {
    solver o;
    o.solve();
  }
}
