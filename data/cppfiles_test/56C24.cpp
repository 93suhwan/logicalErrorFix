#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 4e5 + 1;
const long long MOD = 1e9 + 7;
const long long MOD1 = 1e9 + 7;
const long long INF = 1e9;
long long n, m, k, l, r;
long long dp[60 * 10000 + 5][6];
long long con[60 * 10000 + 5];
vector<int> nc[6];
map<long long, int> label;
vector<vector<int> > adj;
string s;
long long powmod(long long a, long long b) {
  a %= MOD;
  if (a == 0) return 0;
  long long product = 1;
  while (b > 0) {
    if (b & 1) {
      product *= a;
      product %= MOD;
      --b;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return product;
}
int getval(char c) {
  if (c == 'w') return 0;
  if (c == 'b') return 1;
  if (c == 'r') return 2;
  if (c == 'y') return 3;
  if (c == 'g') return 4;
  if (c == 'o') return 5;
}
long long solv(int i, int j) {
  if (con[i] != -1 && con[i] != j) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  long long sum[2] = {0};
  for (auto x : nc[j]) {
    for (int c1 = 0; c1 < adj[i].size(); c1++) {
      sum[c1] = (sum[c1] + solv(adj[i][c1], x)) % MOD;
    }
  }
  if (adj[i].size() == 0) {
    sum[0] = sum[1] = 1;
  }
  if (adj[i].size() == 1) {
    sum[1] = 1;
  }
  dp[i][j] = (sum[0] * sum[1]) % MOD;
  return dp[i][j];
}
void solve() {
  cin >> k >> n;
  memset(dp, -1, sizeof(dp));
  memset(con, -1, sizeof(con));
  long long unused = (1LL << k) - 1;
  nc[0] = {1, 2, 4, 5};
  nc[1] = {0, 2, 3, 5};
  nc[2] = {0, 1, 3, 4};
  nc[3] = {1, 2, 4, 5};
  nc[4] = {0, 2, 3, 5};
  nc[5] = {0, 1, 3, 4};
  int lab = 0;
  map<long long, int> array;
  for (int i = 0; i < n; i++) {
    long long ind, val;
    cin >> ind >> s;
    val = getval(s[0]);
    array[ind] = val;
    while (ind >= 1 && label.count(ind) == 0) {
      label[ind] = lab++;
      unused--;
      ind /= 2;
    }
  }
  adj.assign(lab + 5, vector<int>());
  for (auto i : label) {
    if (array.count(i.first) > 0) {
      con[i.second] = array[i.first];
    }
    if (label.count(2 * i.first) > 0) {
      adj[i.second].push_back(label[i.first * 2]);
    }
    if (label.count(2 * i.first + 1) > 0) {
      adj[i.second].push_back(label[i.first * 2 + 1]);
    }
  }
  long long ans = powmod(4, unused);
  long long sum = 0;
  for (int i = 0; i < 6; i++) {
    sum += solv(label[1LL], i);
    sum %= MOD;
  }
  cout << (ans * sum) % MOD << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
