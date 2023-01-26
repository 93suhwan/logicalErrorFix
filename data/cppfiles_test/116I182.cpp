#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long binp(long long a, long long p) {
  if (p == 0) return 1;
  if (p & 1) {
    return ((long long)a * binp(a, p - 1)) % mod;
  } else {
    long long t = binp(a, p / 2);
    return (t * t) % mod;
  }
}
long long get_cnt(long long key, long long l, vector<vector<long long>> &pos) {
  if (key >= pos.size()) return 0;
  if (pos[key].empty()) return 0;
  if (pos[key].back() < l) return 0;
  long long la = 1, ra = pos[key].size();
  while (la < ra) {
    long long mid = (la + ra + 1) / 2;
    if (pos[key][pos[key].size() - mid] >= l)
      la = mid;
    else
      ra = mid - 1;
  }
  return la;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<vector<long long>> pos(n + 1);
  for (long long i = 0; i < n; i++) pos[a[i]].push_back(i);
  vector<long long> dpprev(n, 0);
  vector<long long> dpcur(n, 0);
  long long cnt0 = 0;
  long long res = 0;
  long long cnt1 = 0;
  for (long long i = 0; i < n; i++)
    if (a[i] == 1) cnt1++;
  res = binp(2, cnt1) - 1;
  for (long long i = 0; i < n; i++) {
    if (a[i]) continue;
    dpprev[i] = binp(2, cnt0);
    cnt0++;
    res =
        (res + ((long long)dpprev[i] * binp(2, get_cnt(2, i + 1, pos))) % mod) %
        mod;
  }
  for (long long i = 1; i <= n; i++) {
    long long id = 0;
    for (auto e : pos[i]) dpcur[e] = 0;
    if (pos[i].size()) {
      while (id < pos[i - 1].size() && pos[i - 1][id] < pos[i][0]) {
        dpcur[pos[i][0]] = (dpcur[pos[i][0]] + dpprev[pos[i - 1][id]]) % mod;
        id++;
      }
      res = (res + ((long long)dpcur[pos[i][0]] *
                    binp(2, get_cnt(i + 2, pos[i][0] + 1, pos))) %
                       mod) %
            mod;
      for (long long j = 1; j < pos[i].size(); j++) {
        dpcur[pos[i][j]] = (dpcur[pos[i][j - 1]] * 2) % mod;
        while (id < pos[i - 1].size() && pos[i - 1][id] < pos[i][j]) {
          dpcur[pos[i][j]] = (dpcur[pos[i][j]] + dpprev[pos[i - 1][id]]) % mod;
          id++;
        }
        res = (res + ((long long)dpcur[pos[i][j]] *
                      binp(2, get_cnt(i + 2, pos[i][j] + 1, pos))) %
                         mod) %
              mod;
      }
    }
    for (auto e : pos[i]) dpprev[e] = dpcur[e];
  }
  cout << res << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test_cnt = 1;
  cin >> test_cnt;
  for (long long test = 1; test <= test_cnt; test++) {
    solve();
  }
  return 0;
}
