#include <bits/stdc++.h>
using namespace std;
struct compare {
  bool operator()(const pair<long long, long long> &a,
                  const pair<long long, long long> &b) {
    return a.first > b.first;
  }
};
bool comp(const pair<long long, long long> &a,
          const pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}
bool compp(const pair<long long, long long> &a,
           const pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long mod_power(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long temp = mod_power(a, b / 2);
  temp %= 998244353;
  temp *= temp;
  temp %= 998244353;
  if (b % 2 == 1) {
    temp *= a;
    temp %= 998244353;
  }
  return temp;
}
long long st = 0;
long long fill(vector<vector<long long> > &dp, long long i, long long j,
               vector<string> &vec, vector<vector<long long> > &vis) {
  long long n = dp.size();
  long long m = dp[0].size();
  if (i >= n || i < 0 || j >= m || j < 0) {
    st = 0;
    return 0;
  }
  if (vis[i][j]) {
    st = st - vis[i][j] + 1;
    return (dp[i][j] = st);
  }
  if (dp[i][j]) {
    st = 0;
    return 0;
  }
  st++;
  vis[i][j] = st;
  long long num = 0;
  if (vec[i][j] == 'U') {
    num = fill(dp, i - 1, j, vec, vis);
  }
  if (vec[i][j] == 'D') {
    num = fill(dp, i + 1, j, vec, vis);
  }
  if (vec[i][j] == 'R') {
    num = fill(dp, i, j + 1, vec, vis);
  }
  if (vec[i][j] == 'L') {
    num = fill(dp, i, j - 1, vec, vis);
  }
  if (dp[i][j]) {
    st = 0;
  } else {
    dp[i][j] = st;
  }
  vis[i][j] = 0;
  return st;
}
void dfs(long long i, long long j, vector<string> &vec,
         vector<vector<long long> > &dp) {
  long long n = dp.size();
  long long m = dp[0].size();
  if (i >= n || i < 0 || j >= m || j < 0) {
    st = 0;
    return;
  }
  if (dp[i][j]) {
    st += dp[i][j];
    return;
  }
  if (vec[i][j] == 'U') {
    dfs(i - 1, j, vec, dp);
  } else if (vec[i][j] == 'D') {
    dfs(i + 1, j, vec, dp);
  } else if (vec[i][j] == 'R') {
    dfs(i, j + 1, vec, dp);
  } else {
    dfs(i, j - 1, vec, dp);
  }
  st++;
  dp[i][j] = st;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<string> vec(n);
    for (long long i = 0; i < n; i++) {
      cin >> vec[i];
    }
    vector<vector<long long> > dp(n, vector<long long>(m, 0));
    vector<vector<long long> > vis(n, vector<long long>(m, 0));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (dp[i][j] == 0) {
          st = 0;
          fill(dp, i, j, vec, vis);
        }
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (dp[i][j] == 0) {
          st = 0;
          dfs(i, j, vec, dp);
        }
      }
    }
    long long ans = 0;
    long long x = 0;
    long long y = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        x = i;
        y = j;
        ans = max(ans, dp[i][j]);
      }
    }
    cout << x + 1 << " " << y + 1 << " " << ans << "\n";
  }
  return 0;
}
