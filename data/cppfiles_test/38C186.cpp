#include <bits/stdc++.h>
using namespace std;
long long q, dp[100005], a[555555], b[555555], k, l, m, n, o, p;
map<long long, long long> mp;
vector<long long> adj[555555];
const long long mod = 1e9 + 7;
string s[1000005];
void solve() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = ' ' + s[i];
  }
  for (long long i = 1; i <= m; i++) b[i] = 0;
  for (long long i = 1; i < m; i++) {
    for (long long j = 1; j < n; j++) {
      if (s[j][i + 1] == 'X' && s[j + 1][i] == 'X') {
        b[i] = 1;
        break;
      }
    }
    b[i] += b[i - 1];
  }
  cin >> l;
  while (l--) {
    cin >> o >> p;
    if (o == p) {
      cout << "YES" << endl;
      continue;
    }
    p--;
    cout << (b[p] - b[o - 1] ? "NO" : "YES") << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  q = 1;
  while (q--) {
    solve();
  }
}
