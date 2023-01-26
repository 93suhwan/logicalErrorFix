#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int read() {
  int ans = 0, flag = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') {
      flag = -1;
      ch = getchar();
      break;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    ans = ans * 10 + ch - '0';
    ch = getchar();
  }
  return ans * flag;
}
int GetLCS(string s1, string s2) {
  int size = s1.size();
  int curMax = 0;
  vector<vector<int> > DP(size + 1, vector<int>(size + 1, 0));
  for (int i = 0; i <= size; i++) {
    DP[i][0] = 0;
    DP[0][i] = 0;
  }
  for (int i = 1; i <= size; i++)
    for (int j = 1; j <= size; j++) {
      if (s1[i - 1] == s2[j - 1])
        DP[i][j] = DP[i - 1][j - 1] + 1;
      else
        DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
      if (DP[i][j] > curMax) curMax = DP[i][j];
    }
  return curMax;
}
bool bz[30];
int d[30], k[30], dd[30];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int u = 0;
    for (int i = 0; i <= 25; i++) bz[i] = true;
    int n;
    cin >> n;
    string second, ss;
    cin >> second;
    int first = 0;
    for (int i = 0; i < n; i++) {
      if (bz[second[i] - 'a']) {
        bz[second[i] - 'a'] = false;
        ss += second[i];
      }
    }
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
      if (second[i] != second[j]) {
        first = 1;
        break;
      }
    }
    if (!first) {
      cout << 0 << endl;
      continue;
    }
    string w[26];
    for (int i = 0; i < ss.size(); i++) {
      for (int j = 0; j < n; j++) {
        if (second[j] == ss[i]) {
          continue;
        } else
          w[i] += second[j];
      }
      first = 0;
      int z, j;
      for (z = 0, j = w[i].size() - 1; z <= j; z++, j--) {
        if (w[i][z] != w[i][j]) {
          first = 1;
          break;
        }
      }
      if (first)
        continue;
      else {
        d[++u] = i;
      }
    }
    if (u == 0) {
      cout << -1 << endl;
      continue;
    }
    int minn = 1e9;
    for (int i = 1; i <= u; i++) {
      char g = ss[d[i]];
      int l = 0, r = n - 1;
      int ans = 0;
      while (l <= r) {
        if (second[l] == second[r]) {
          l++;
          r--;
          continue;
        } else if (second[l] == g) {
          l++;
          ans++;
        } else if (second[r] == g) {
          r--;
          ans++;
        }
      }
      minn = min(minn, ans);
    }
    cout << minn << endl;
  }
  return 0;
}
