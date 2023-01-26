#include <bits/stdc++.h>
using namespace std;
struct compare {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
  }
};
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}
bool compp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int mod_power(int a, int b) {
  if (b == 0) {
    return 1;
  }
  int temp = mod_power(a, b / 2);
  temp %= 998244353;
  temp *= temp;
  temp %= 998244353;
  if (b % 2 == 1) {
    temp *= a;
    temp %= 998244353;
  }
  return temp;
}
int st = 0;
int n, m;
int dp[2001][2001];
int vis[2001][2001];
string vec[2001];
int fill(int i, int j) {
  if (i >= n || i < 0 || j >= m || j < 0) {
    st = 0;
    return 0;
  }
  if (vis[i][j]) {
    st = st - vis[i][j] + 1;
    return (dp[i][j] = st);
  }
  if (dp[i][j] != -1) {
    st = 0;
    return 0;
  }
  st++;
  vis[i][j] = st;
  int num = 0;
  if (vec[i][j] == 'U') {
    num = fill(i - 1, j);
  }
  if (vec[i][j] == 'D') {
    num = fill(i + 1, j);
  }
  if (vec[i][j] == 'R') {
    num = fill(i, j + 1);
  }
  if (vec[i][j] == 'L') {
    num = fill(i, j - 1);
  }
  if (dp[i][j] != -1) {
    st = 0;
  } else {
    dp[i][j] = st;
  }
  vis[i][j] = 0;
  return st;
}
void dfs(int i, int j) {
  if (i >= n || i < 0 || j >= m || j < 0) {
    st = 0;
    return;
  }
  if (dp[i][j] > 0) {
    st += dp[i][j];
    return;
  }
  if (vec[i][j] == 'U') {
    dfs(i - 1, j);
  } else if (vec[i][j] == 'D') {
    dfs(i + 1, j);
  } else if (vec[i][j] == 'R') {
    dfs(i, j + 1);
  } else {
    dfs(i, j - 1);
  }
  st++;
  dp[i][j] = st;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = -1;
        vis[i][j] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dp[i][j] == -1) {
          st = 0;
          fill(i, j);
        }
      }
    }
    int ans = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dp[i][j] == 0) {
          st = 0;
          dfs(i, j);
        }
        if (ans < dp[i][j]) {
          ans = dp[i][j];
          x = i;
          y = j;
        }
      }
    }
    cout << x + 1 << " " << y + 1 << " " << ans << "\n";
  }
  return 0;
}
