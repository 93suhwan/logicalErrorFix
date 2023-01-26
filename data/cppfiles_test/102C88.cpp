#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long k, A, h, n;
long long pw[100];
vector<long long> positions;
map<long long, long long> mp[50];
long long ans[50];
pair<long long, long long> eval(long long mask, long long l, long long r) {
  queue<long long> q;
  for (long long i = l; i <= r; i++) q.push(i);
  long long score = 0;
  for (long long i = 0; i < (n / 2) - 1; i++) {
    long long p1 = q.front();
    q.pop();
    long long p2 = q.front();
    q.pop();
    if ((mask >> i) & 1) swap(p1, p2);
    q.push(p1);
    score += p2 * pw[positions[i]];
    score %= MOD;
    ans[p2] = positions[i];
  }
  return {score, q.front()};
}
void solve() {
  cin >> k >> A >> h;
  n = (1LL << k);
  for (long long i = 0; i < k - 1; i++)
    for (long long j = 0; j < (1LL << (k - i - 2)); j++)
      positions.push_back((1LL << (k - i - 1)) + 1);
  pw[0] = 1;
  for (long long i = 1; i < 100; i++) pw[i] = (pw[i - 1] * A) % MOD;
  for (long long i = 0; i < (1LL << ((n / 2) - 1)); i++) {
    auto temp = eval(i, 1, n / 2);
    mp[temp.second][temp.first] = i;
  }
  for (long long i = 0; i < (1LL << ((n / 2) - 1)); i++) {
    auto temp = eval(i, (n / 2) + 1, n);
    for (long long j = 1; j <= n / 2; j++) {
      for (long long v = 0; v <= 1; v++) {
        long long need =
            h - temp.first - temp.second * pw[v + 1] - j * pw[2 - v];
        need %= MOD;
        if (need < 0) need += MOD;
        if (mp[j].find(need) != mp[j].end()) {
          eval(mp[j][need], 1, n / 2);
          ans[temp.second] = v + 1;
          ans[j] = 2 - v;
          for (long long i = 1; i <= n; i++) cout << ans[i] << ' ';
          return;
        }
      }
    }
  }
  cout << -1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
