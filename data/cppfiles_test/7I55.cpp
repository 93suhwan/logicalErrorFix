#include <bits/stdc++.h>
using namespace std;
string a, b;
int n, m;
int p[510];
void kmppreprocess() {
  int i = 0, j = -1;
  p[0] = -1;
  while (i < m) {
    while (j >= 0 && b[i] != b[j]) j = p[j];
    i++, j++;
    p[i] = j;
  }
}
int kmpsearch(string s) {
  int n = s.size();
  int i = 0, j = 0, tot = 0;
  while (i < n) {
    while (j >= 0 && s[i] != b[j]) j = p[j];
    i++, j++;
    if (j == m) {
      tot++;
      j = p[j];
    }
  }
  return tot;
}
inline int dive(int x, int y) {
  int tot = 0;
  for (int i = y, j = m - 1; i >= x; i--, j--) tot += b[j] != a[i];
  return tot;
}
int dp[510][510], dp2[510][510];
int main() {
  cin >> n >> m >> a >> b;
  kmppreprocess();
  for (int i = 0; i < 510; i++)
    for (int j = 0; j < 510; j++) dp[i][j] = 1000000000;
  dp[0][0] = 0;
  for (int i = m - 1; i < n; i++) {
    string s = a.substr(0, i - m + 1) + b;
    int x = dive(i - m + 1, i);
    dp[i][kmpsearch(s)] = x;
    int j;
    for (j = i - 1; j >= i - m + 1 && j - m + 1 >= 0; j--) {
      int d = m - (i - j);
      if (b.substr(0, d) == b.substr(i - j, d)) {
        int x = dive(j + 1, i);
        s = b.substr(1, m - 1) + b.substr(d, i - j);
        int y = kmpsearch(s);
        for (int k = y; k < 510; k++) {
          if (dp[j][k - y] != 1000000000)
            dp[i][k] = min(dp[i][k], dp[j][k - y] + x);
        }
      }
    }
    for (; j - m + 1 >= 0; j--) {
      string s = b.substr(1, m - 1) + a.substr(j + 1, i - j - m) + b;
      int y = kmpsearch(s);
      for (int k = y; k < 510; k++) {
        if (dp[j][k - y] != 1000000000)
          dp[i][k] = min(dp[i][k], dp[j][k - y] + x);
      }
    }
  }
  int pos = 0;
  for (int i = n - m; i >= 0; i--) {
    if (a.substr(i, m) == b) {
      pos = i + 1;
      break;
    }
  }
  for (int i = pos + 1; i < n; i++) {
    for (int j = 0; j < 510; j++) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
  }
  vector<int> v;
  for (int i = 0; i <= n - m; i++)
    if (a.substr(i, m) == b) v.push_back(i);
  for (int i = 0; i < 510; i++)
    for (int j = 0; j < 510; j++) dp2[i][j] = 1000000000;
  int siz = v.size();
  int num[510];
  for (int i = 0; i < n; i++) {
    int x = 0;
    while (x < siz && v[x] <= i) x++;
    dp2[i][x] = 0;
    num[i] = x;
    if (i > 0) {
      int diff = num[i] - num[i - 1];
      for (int j = diff; j < 510; j++)
        dp2[i][j] = min(dp2[i][j], dp2[i - 1][j - diff]);
      if (i >= m) {
        for (int j = 0; j < 510; j++) {
          dp2[i][j] = min(dp2[i][j], dp2[i - m][j] + 1);
        }
      } else if (num[i])
        dp2[i][0] = 1;
    } else if (num[i]) {
      dp2[i][0] = 1;
    }
  }
  for (int j = 0; j < siz; j++) {
    dp[n - 1][j] = dp2[n - 1][j];
  }
  for (int i = 0; i <= n - m + 1; i++)
    cout << (dp[n - 1][i] == 1000000000 ? -1 : dp[n - 1][i]) << " ";
}
