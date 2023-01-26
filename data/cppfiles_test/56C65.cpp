#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
long long dp[(60 * 10000) + 5][6];
vector<long long> color[6];
vector<vector<int> > adj;
map<long long, int> label;
long long c[(60 * 10000) + 5];
long long solve(int i, int j) {
  if (c[i] != -1 && c[i] != j) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  long long ans = 0;
  long long sum[2] = {0};
  for (auto x : color[j]) {
    for (long long j = 0; j < adj[i].size(); j++) {
      sum[j] += solve(adj[i][j], x);
      sum[j] %= INF;
    }
  }
  if (adj[i].empty()) {
    sum[0] = sum[1] = 1;
  }
  if ((long long)adj[i].size() == 1) {
    sum[1] = 1;
  }
  ans = (sum[0] * sum[1]) % INF;
  return dp[i][j] = ans;
}
long long power(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2, mod);
  ans *= ans;
  ans %= mod;
  if (b % 2) {
    ans *= a;
  }
  return ans % mod;
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  color[0] = {1, 2, 4, 5};
  color[1] = {0, 2, 3, 5};
  color[2] = {0, 1, 3, 4};
  color[3] = {1, 2, 4, 5};
  color[4] = {0, 2, 3, 5};
  color[5] = {0, 1, 3, 4};
  map<string, long long> mp;
  mp["white"] = 0;
  mp["blue"] = 1;
  mp["red"] = 2;
  mp["yellow"] = 3;
  mp["green"] = 4;
  mp["orange"] = 5;
  memset(dp, -1, sizeof dp);
  memset(c, -1, sizeof c);
  long long k;
  cin >> k;
  long long n;
  cin >> n;
  long long posoi = (1LL << k) - 1;
  int lab = 0;
  map<long long, int> ar;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    string s;
    cin >> s;
    ar[x] = mp[s];
    long long cur = x;
    while (cur >= 1 && !label.count(cur)) {
      label[cur] = lab;
      lab++;
      posoi--;
      cur /= 2;
    }
  }
  adj.assign(lab + 5, vector<int>());
  for (auto x : label) {
    if (ar.count(x.first)) {
      c[x.second] = ar[x.first];
    }
    if (label.count(x.first * 2)) {
      adj[x.second].push_back(label[x.first * 2]);
    }
    if (label.count(x.first * 2 + 1)) {
      adj[x.second].push_back(label[x.first * 2 + 1]);
    }
  }
  long long ans = power(4, posoi, INF);
  long long sum = 0;
  for (long long j = 0; j < 6; j++) {
    sum += solve(label[1], j);
    sum %= INF;
  }
  ans *= sum;
  ans %= INF;
  cout << ans << "\n";
}
