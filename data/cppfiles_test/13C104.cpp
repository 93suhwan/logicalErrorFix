#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int dp[N][N][(N * N) / 2 + 1];
map<pair<pair<int, int>, int>, vector<string>> actAns;
int fun(int n, int m, int k) {
  if (dp[n][m][k] != -1) return dp[n][m][k];
  int pos = 0;
  if (n == 0 || m == 0) {
    pos = (k == 0);
    return dp[n][m][k] = pos;
  }
  if (n == 1) {
    if (m % 2 == 0 && 2 * k == m) pos = 1;
    return dp[n][m][k] = pos;
  }
  if (m == 1) {
    if (k == 0 && n % 2 == 0) pos = 1;
    return dp[n][m][k] = pos;
  }
  if (k == 0) {
    if (n % 2 == 0) pos = 1;
    return dp[n][m][k] = pos;
  }
  if (k == (n * m) / 2) {
    if (m % 2 == 0) pos = 1;
    return dp[n][m][k] = pos;
  }
  int mx = m / 2;
  for (int cnt = 0; cnt <= mx && pos == 0; cnt++) {
    int newK = k - 2 * cnt;
    if (newK >= 0) {
      pos |= fun(n - 2, m, newK);
      if (pos) {
      }
    } else
      break;
  }
  return dp[n][m][k] = pos;
}
int solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int pos = fun(n, m, k);
  cout << (pos == 1 ? "YES\n" : "NO\n");
  if (pos) {
    vector<string> ans;
    int ch = 0;
    if (n % 2 == 1) {
      string temp = "";
      for (int i = 0; i < m; i += 2) {
        temp += (char)(ch + 'a');
        temp += (char)(ch + 'a');
        ch ^= 1;
      }
      k -= m / 2;
      ans.push_back(temp);
      n--;
    }
    while (n > 0) {
      string temp1 = "";
      string temp2 = "";
      int mx = m / 2;
      for (int cnt = 0; cnt <= mx; cnt++) {
        int newK = k - 2 * cnt;
        if (newK >= 0) {
          if (fun(n - 2, m, newK)) {
            for (int i = 0; i < cnt; i++) {
              while ((long long int)ans.size() != 0 &&
                     ((ans.back()[2 * i] - 'a') == ch ||
                      (ans.back()[2 * i + 1] - 'a') == ch)) {
                ch++;
                ch %= 26;
              }
              temp1 += (char)(ch + 'a');
              temp1 += (char)(ch + 'a');
              ch++;
              ch %= 26;
              temp2 += (char)(ch + 'a');
              temp2 += (char)(ch + 'a');
            }
            for (int i = 2 * cnt; i < m; i++) {
              while (
                  ((long long int)temp1.size() != 0 &&
                   (temp1.back() - 'a' == ch || temp2.back() - 'a' == ch)) ||
                  ((long long int)ans.size() != 0 &&
                   ((ans.back()[(long long int)temp1.size()] - 'a') == ch))) {
                ch++;
                ch %= 26;
              }
              temp1 += (char)(ch + 'a');
              temp2 += (char)(ch + 'a');
            }
            ans.push_back(temp1);
            ans.push_back(temp2);
            n -= 2;
            k -= 2 * cnt;
            break;
          }
        } else
          break;
      }
    }
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << "\n";
  }
  return 0;
}
int main() {
  memset(dp, -1, sizeof dp);
  auto start = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) solve();
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
}
