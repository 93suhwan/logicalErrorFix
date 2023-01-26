#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2010;
map<string, int> id;
vector<int> g[6];
int k;
long long dp[70];
map<long long, int> mp;
map<long long, long long*> dpp;
int main() {
  id["yellow"] = 0;
  id["blue"] = 1;
  id["red"] = 2;
  id["white"] = 3;
  id["green"] = 4;
  id["orange"] = 5;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (i % 3 != j % 3) {
        g[i].push_back(j);
      }
    }
  }
  cin >> k;
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= k; i++) dp[i] = dp[i - 1] * dp[i - 1] % mod * 16 % mod;
  int n;
  cin >> n;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    string s;
    cin >> s;
    mp[a] = id[s];
    while (a) {
      dpp[a] = new long long[6];
      v.push_back(a);
      a = (a >> 1);
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (long long x : v) {
    int l = 0;
    long long t = x;
    while (t) {
      l++;
      t = (t >> 1);
    }
    for (int i = 0; i < 6; i++) {
      if (mp.find(x) != mp.end() && mp[x] != i) {
        dpp[x][i] = 0;
        continue;
      }
      long long res1 = 0;
      if (dpp.find(x << 1) == dpp.end())
        res1 = (k == l ? 1 : 4) * dp[k - l] % mod;
      else {
        for (int j : g[i]) res1 = (res1 + dpp[x << 1][j]) % mod;
      }
      long long res2 = 0;
      if (dpp.find(x << 1 | 1) == dpp.end())
        res2 = (k == l ? 1 : 4) * dp[k - l] % mod;
      else {
        for (int j : g[i]) res2 = (res2 + dpp[x << 1 | 1][j]) % mod;
      }
      dpp[x][i] = res1 * res2 % mod;
    }
  }
  long long ans = 0;
  for (int i = 0; i < 6; i++) ans = (ans + dpp[1][i]) % mod;
  cout << ans << endl;
  return 0;
}
