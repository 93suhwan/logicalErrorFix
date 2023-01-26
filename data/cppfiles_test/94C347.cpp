#include <bits/stdc++.h>
using namespace std;
string n;
long long len;
long long dp[10][2][2];
bool checkCarry(long long pos) {
  if (pos >= len) return false;
  return true;
}
long long func(long long i, long long carry, long long carryNext) {
  if (i == len) {
    if (carry || carryNext) return 0;
    return 1;
  }
  if (dp[i][carry][carryNext] != -1) {
    return dp[i][carry][carryNext];
  }
  long long ans = 0;
  for (char c = '0'; c <= '9'; c++) {
    for (char d = '0'; d <= '9'; d++) {
      long long sum = (c - '0') + (d - '0') + carry;
      long long val = sum % 10;
      long long tmpCarry = sum / 10;
      if ((char)(val + '0') == n[len - 1 - i]) {
        ans += func(i + 1, carryNext, tmpCarry);
      }
    }
  }
  return dp[i][carry][carryNext] = ans;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    len = n.size();
    memset(dp, -1, sizeof dp);
    cout << func(0, 0, 0) - 2 << endl;
  }
  return 0;
}
