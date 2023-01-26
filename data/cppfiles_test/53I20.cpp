#include <bits/stdc++.h>
using namespace std;
vector<long long> vl, wg;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long ksac(long long n, long long c, vector<vector<long long> > &dp) {
  long long result = 0;
  if (dp[n][c] != -1) return dp[n][c];
  if (n == 0 || c == 0) {
    return 0;
  } else if (wg[n] > c) {
    result = ksac(n - 1, c, dp);
  } else {
    unsigned long long tmp1, tmp2;
    tmp1 = vl[n] + ksac(n - 1, c - wg[n], dp);
    tmp2 = ksac(n - 1, c, dp);
    result = max(tmp1, tmp2);
  }
  dp[n][c] = result;
  return result;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long ans = 0, n, m, k, cnt = 0;
    string s;
    char c;
    cin >> n >> c >> s;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != c) {
        cnt++;
        break;
      }
    }
    if (cnt > 0 && s[n - 1] == c) {
      cout << "1 \n" << n << endl;
    } else if (cnt > 0 && s[n - 1] != c) {
      cout << "2 \n" << n << " " << n - 1 << endl;
    } else
      cout << "0" << endl;
  }
  return 0;
}
