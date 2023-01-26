#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int CASOS;
  cin >> CASOS;
  for (int caso = 1; caso <= CASOS; caso++) {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    for (auto &i : x) cin >> i;
    vector<pair<int, int>> c(m);
    vector<string> s(n);
    for (auto &i : s) cin >> i;
    vector<int> p(m), aux(m);
    ll ans = LLONG_MIN;
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int j = 0; j < m; j++) {
        c[j] = {0, j};
        for (int i = 0; i < n; i++) {
          if (mask & (1 << i))
            c[j].first -= (s[i][j] - '0');
          else
            c[j].first += (s[i][j] - '0');
        }
      }
      sort((c).begin(), (c).end());
      ll cur = 0;
      for (int i = 0; i < m; i++) {
        aux[c[i].second] = i + 1;
        cur += (ll)(i + 1) * (ll)c[i].first;
      }
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i))
          cur += x[i];
        else
          cur -= x[i];
      }
      if (ans < cur) {
        ans = cur;
        p = aux;
      }
    }
    for (auto i : p) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}
