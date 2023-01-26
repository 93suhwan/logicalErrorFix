#include <bits/stdc++.h>
using namespace std;
vector<long long int> prefix_function(string s) {
  long long int n = (long long int)s.length();
  vector<long long int> pi(n);
  for (long long int i = 1; i < n; i++) {
    long long int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
void compute_automaton(string s, vector<vector<long long int>>& aut) {
  s += '#';
  long long int n = s.size();
  vector<long long int> pi = prefix_function(s);
  aut.assign(n, vector<long long int>(2));
  for (long long int i = 0; i < n; i++) {
    for (long long int c = 0; c < 2; c++) {
      if (i > 0 && '0' + c != s[i])
        aut[i][c] = aut[pi[i - 1]][c];
      else
        aut[i][c] = i + ('0' + c == s[i]);
    }
  }
}
long long int dp[505][505];
long long int inf = 1000000000;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  vector<vector<long long int>> aut;
  compute_automaton(b, aut);
  for (long long int i = 0; i <= 500; i++) {
    for (long long int j = 0; j <= m; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for (long long int i = 0; i < n; i++) {
    long long int dpc[505][505];
    for (long long int j = 0; j <= 500; j++) {
      for (long long int k = 0; k <= m; k++) {
        dpc[j][k] = inf;
      }
    }
    long long int c = a[i] - '0';
    for (long long int j = 0; j <= 500; j++) {
      for (long long int k = 0; k <= m; k++) {
        if (dp[j][k] == inf) {
          continue;
        }
        if (aut[k][c] == m) {
          dpc[j + 1][aut[k][c]] = min(dpc[j + 1][aut[k][c]], dp[j][k]);
        } else {
          dpc[j][aut[k][c]] = min(dpc[j][aut[k][c]], dp[j][k]);
        }
        if (aut[k][c ^ 1] == m) {
          dpc[j + 1][aut[k][c ^ 1]] =
              min(dpc[j + 1][aut[k][c ^ 1]], dp[j][k] + 1);
        } else {
          dpc[j][aut[k][c ^ 1]] = min(dpc[j][aut[k][c ^ 1]], dp[j][k] + 1);
        }
      }
    }
    for (long long int j = 0; j <= 500; j++) {
      for (long long int k = 0; k <= m; k++) {
        dp[j][k] = dpc[j][k];
      }
    }
  }
  for (long long int i = 0; i <= n - m + 1; i++) {
    long long int v = inf;
    for (long long int j = 0; j <= m; j++) {
      v = min(v, dp[i][j]);
    }
    if (v < inf) {
      cout << v << " ";
    } else {
      cout << "-1 ";
    }
  }
}
