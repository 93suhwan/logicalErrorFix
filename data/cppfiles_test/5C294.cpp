#include <bits/stdc++.h>
using vi = std::vector<long long int>;
using vvi = std::vector<vi>;
using pii = std::pair<long long int, long long int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
using namespace std;
const long long int inf = 1e18 + 10;
const long long int N = 2e6 + 10;
string s, t;
long long int n, vis[N], cnt, koi;
void solve() {
  cnt = koi = 0;
  cin >> n >> s >> t;
  for (long long int i = 0; i < n; i++)
    if (t[i] == '1') {
      if (s[i] == '0') {
        s[i] = t[i] = '0';
        vis[i] = 1;
      } else if (s[i - 1] == t[i]) {
        s[i - 1] = t[i] = '0';
        vis[i] = 1;
      } else if (s[i + 1] == t[i]) {
        s[i + 1] = t[i] = '0';
        vis[i] = 1;
      }
      if (vis[i] == 1) {
        koi++;
        vis[i] = 0;
      }
    }
  cout << koi;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
