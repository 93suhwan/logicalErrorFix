#include <bits/stdc++.h>
using namespace std;
vector<long long> ans;
long long pw[205];
set<long long> stc[2], str[2];
map<long long, vector<long long>> mpc[2], mpr[2];
long long cur;
void bct(vector<long long> v) {
  if (v.size() == 1) {
    long long hsh = 0;
    ans[v[0]] = 1;
    for (long long i = 1; i < ans.size(); i++)
      if (ans[i]) {
        hsh = (hsh + i * pw[ans[i]]) % 998244353;
      }
    stc[cur].insert(hsh);
    mpc[cur][hsh] = ans;
    ans[v[0]] = 2;
    hsh = 0;
    for (long long i = 1; i < ans.size(); i++)
      if (ans[i]) hsh = (hsh + i * pw[ans[i]]) % 998244353;
    str[cur].insert(hsh);
    mpr[cur][hsh] = ans;
    ans[v[0]] = 0;
    return;
  }
  long long n = v.size() / 2;
  for (long long mask = 0; mask < (1 << n); mask++) {
    vector<long long> winner, looser;
    for (long long j = 0; j < n; j++) {
      if (mask & (1 << j)) {
        winner.push_back(v[2 * j]);
        looser.push_back(v[2 * j + 1]);
      } else {
        winner.push_back(v[2 * j + 1]);
        looser.push_back(v[2 * j]);
      }
      ans[looser.back()] = v.size() + 1;
    }
    bct(winner);
    for (auto &cv : looser) ans[cv] = 0;
  }
}
void print(vector<long long> v1, vector<long long> v2) {
  for (long long i = 1; i < v1.size(); i++) cout << max(v1[i], v2[i]) << ' ';
  cout << endl;
}
void solve() {
  long long k, a, h;
  cin >> k >> a >> h;
  long long n = (1 << k);
  pw[0] = 1;
  for (long long i = 1; i <= n; i++) pw[i] = pw[i - 1] * a % 998244353;
  vector<long long> v1, v2;
  ans.resize(n + 1);
  for (long long i = 1; i <= n; i++)
    if (i <= (n / 2))
      v1.push_back(i);
    else
      v2.push_back(i);
  long long sum = 0;
  sum += pw[1] * 5;
  sum += pw[5] * 6;
  sum += pw[5] * 7;
  sum += pw[3] * 8;
  bct(v1);
  cur++;
  bct(v2);
  for (auto &cv : stc[0]) {
    long long laagbe = (h - cv + 998244353) % 998244353;
    if (str[1].find(laagbe) == str[1].end()) continue;
    print(mpc[0][cv], mpr[1][laagbe]);
    return;
  }
  for (auto &cv : stc[1]) {
    long long laagbe = (h - cv + 998244353) % 998244353;
    if (str[0].find(laagbe) == str[0].end()) continue;
    print(mpc[1][cv], mpr[0][laagbe]);
    return;
  }
  cout << -1 << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
