#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s1;
    cin >> s1;
    n = s1.size();
    vector<int> dp[2];
    for (int i = 0, j = 0; i < n; i++) {
      if (s1[i] == '1' or s1[i] == '0') dp[i % 2].push_back(s1[i] - '0');
      if (s1[i] == '?') {
        if (i % 2 == 0)
          dp[i % 2].push_back(1);
        else
          dp[i % 2].push_back(0);
      }
      if (i & 1) j++;
    }
    int coun1 = 0, coun2 = 0;
    int step = 0;
    for (int i = 0, j = 0, fir = 0, sec = 0; i < 5;) {
      if (dp[j][i] == 1) coun1++;
      step++;
      if (coun1 > 5 - sec + coun2) break;
      j = j ^ 1;
      fir++;
      if (coun2 > 5 - fir + coun1) break;
      if (dp[j][i] == 1) coun2++;
      step++;
      if (coun2 > 5 - fir + coun1) break;
      sec++;
      if (coun1 > 5 - sec + coun2) break;
      j = j ^ 1;
      i++;
    }
    dp[0].clear();
    dp[1].clear();
    for (int i = 0, j = 0; i < n; i++) {
      if (s1[i] == '1' or s1[i] == '0') dp[i % 2].push_back(s1[i] - '0');
      if (s1[i] == '?') {
        if (i % 2 == 1)
          dp[i % 2].push_back(1);
        else
          dp[i % 2].push_back(0);
      }
      if (i & 1) j++;
    }
    int rem = step;
    coun1 = 0, coun2 = 0;
    step = 0;
    for (int i = 0, j = 0, fir = 0, sec = 0; i < 5;) {
      if (dp[j][i] == 1) coun1++;
      step++;
      if (coun1 > 5 - sec + coun2) break;
      j = j ^ 1;
      fir++;
      if (coun2 > 5 - fir + coun1) break;
      if (dp[j][i] == 1) coun2++;
      step++;
      if (coun2 > 5 - fir + coun1) break;
      sec++;
      if (coun1 > 5 - sec + coun2) break;
      j = j ^ 1;
      i++;
    }
    step = min(rem, step);
    cout << step << endl;
  }
  return 0;
}
