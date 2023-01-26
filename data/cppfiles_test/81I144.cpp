#include <bits/stdc++.h>
using namespace std;
void amn(long long &x, long long y) { x = min(x, y); }
void amx(long long &x, long long y) { x = max(x, y); }
const long long INF = 1e18;
const long long N = 3e5 + 5;
long long n, q;
string s;
long long pref[N][2][2];
void solve() {
  cin >> n >> q;
  cin >> s;
  s = "#" + s;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 0; j < 2; j++) {
      for (long long k = 0; k < 2; k++) {
        pref[i][j][k] = 0;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (s[i] == '+') {
      pref[i][i % 2][0]++;
    } else {
      pref[i][i % 2][1]++;
    }
    for (long long j = 0; j < 2; j++) {
      for (long long k = 0; k < 2; k++) {
        pref[i][j][k] += pref[i - 1][j][k];
      }
    }
  }
  for (long long i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    long long pos[2], neg[2];
    for (long long i = 0; i < 2; i++) {
      pos[i] = pref[r][i][0] - pref[l - 1][i][0];
      neg[i] = pref[r][i][1] - pref[l - 1][i][1];
    }
    long long k = min(pos[0], pos[1]);
    pos[0] -= k, pos[1] -= k;
    k = min(neg[0], neg[1]);
    neg[0] -= k, neg[1] -= k;
    vector<long long> v;
    for (long long i = 0; i < 2; i++) {
      v.push_back(pos[i]);
      v.push_back(neg[i]);
    }
    sort(v.begin(), v.end());
    long long ans = v[0] + v[1] + v[2] + (v[3] % 2);
    cout << ans << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
