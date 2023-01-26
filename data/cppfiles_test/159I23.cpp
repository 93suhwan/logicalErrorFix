#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const long long inf = 3e18;
const long long MAXN = 1e5 + 10;
const long long R = 1 << 19;
const long long mod = 1e9 + 7;
const long long LOGN = 21;
void solve() {
  long long n;
  cin >> n;
  vector<long long> cur(n + 1, 1);
  if (n % 2 == 1) {
    cur[n] = 0;
    --n;
  }
  n /= 2;
  cur[n] = 0;
  if (n % 2 != 0) cur[2] = 0;
  cur[1] = 1;
  vector<long long> ans;
  for (long long i = 1; i < (long long)cur.size(); ++i)
    if (cur[i]) ans.push_back(i);
  cout << (long long)ans.size() << "\n";
  for (auto x : ans) cout << x << " ";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
