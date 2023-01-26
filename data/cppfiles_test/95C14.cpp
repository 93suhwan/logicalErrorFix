#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long;
void f_io() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  cout.tie(nullptr);
}
const ll MOD = 998244353;
ll gc(ll a, ll b) {
  if (!a || !b) {
    return max(a, b);
  }
  assert(b != 0);
  ll r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}
inline ll mult(ll a, ll b) { return ((a % MOD) * 1LL * (b % MOD)) % MOD; }
inline ll add(ll a, ll b) {
  b = (b % MOD + MOD) % MOD;
  return (a + b) % MOD;
}
ll pw(ll a, ll b) {
  if (b < 0) {
    return 1;
  }
  ll r = 1;
  while (b) {
    if (b & 1) {
      r = mult(a, r);
    }
    b >>= 1;
    a = mult(a, a);
  }
  return r;
}
ll nc2(ll n) { return ((n - 1) * 1LL * (n)) / 2; }
ll nc3(ll n) { return ((n - 1) * (n - 2) * n) / 6; }
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int ar[n][m];
    pair<int, int> l[n][m], r[n][m];
    bool fl = 0;
    int r1 = -1, r2 = -1, k = -1;
    for (int i = 0; i < n; ++i) {
      int mi = MOD, ma = -MOD;
      for (int j = 0; j < m; ++j) {
        cin >> ar[i][j];
        mi = min(ar[i][j], mi);
        ma = max(ar[i][j], ma);
        l[i][j] = make_pair(mi, ma);
      }
      mi = +MOD, ma = -MOD;
      for (int j = m - 1; j >= 0; --j) {
        mi = min(ar[i][j], mi);
        ma = max(ar[i][j], ma);
        r[i][j] = make_pair(mi, ma);
      }
    }
    string s;
    for (int i = 0; i < n; i++) {
      s.push_back('B');
    }
    for (int j = 0; j + 1 < m && !fl; ++j) {
      vector<pair<pair<int, int>, int>> vpp;
      multiset<pair<int, int>> ms;
      for (int i = 0; i < n; ++i) {
        vpp.push_back(make_pair(l[i][j], i));
        ms.insert(make_pair(r[i][j + 1].second, i));
      }
      sort(vpp.begin(), vpp.end());
      multiset<pair<int, int>> se;
      int v = MOD;
      for (int i = 0; i < vpp.size() && !fl; ++i) {
        while (se.size() && se.begin()->first < vpp[i].first.first) {
          se.erase(se.begin());
        }
        if (i > 0 && ms.size() && se.size() == 0 && v > ms.rbegin()->first) {
          k = j + 1;
          fl = 1;
          for (int x = i; x < n; ++x) {
            s[vpp[x].second] = 'R';
          }
        }
        ms.erase(
            ms.find(make_pair(r[vpp[i].second][j + 1].second, vpp[i].second)));
        se.insert(make_pair(vpp[i].first.second, vpp[i].second));
        v = min(r[vpp[i].second][j + 1].first, v);
      }
    }
    if (fl) {
      cout << "YES\n";
      cout << s << " " << k << "\n";
    } else {
      cout << "NO\n";
    }
  }
}
