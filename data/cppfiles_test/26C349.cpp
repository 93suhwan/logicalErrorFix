#include <bits/stdc++.h>
using namespace std;
int dp(string str, int round, int evenScore, int oddScore, int evenRemaining,
       int oddRemaining, int kicks) {
  if (round > 10) return 10;
  if (evenScore > oddScore + oddRemaining) return kicks;
  if (oddScore > evenScore + evenRemaining) return kicks;
  if (round % 2 == 1) {
    if (str[round - 1] == '1') {
      return dp(str, round + 1, evenScore, oddScore + 1, evenRemaining,
                oddRemaining - 1, kicks + 1);
    } else if (str[round - 1] == '?') {
      int tmp1 = dp(str, round + 1, evenScore, oddScore + 1, evenRemaining,
                    oddRemaining - 1, kicks + 1);
      int tmp2 = dp(str, round + 1, evenScore, oddScore, evenRemaining,
                    oddRemaining - 1, kicks + 1);
      return min(tmp1, tmp2);
    } else {
      return dp(str, round + 1, evenScore, oddScore, evenRemaining,
                oddRemaining - 1, kicks + 1);
    }
  } else {
    if (str[round - 1] == '1') {
      return dp(str, round + 1, evenScore + 1, oddScore, evenRemaining - 1,
                oddRemaining, kicks + 1);
    } else if (str[round - 1] == '?') {
      int tmp1 = dp(str, round + 1, evenScore + 1, oddScore, evenRemaining - 1,
                    oddRemaining, kicks + 1);
      int tmp2 = dp(str, round + 1, evenScore, oddScore, evenRemaining - 1,
                    oddRemaining, kicks + 1);
      return min(tmp1, tmp2);
    } else {
      return dp(str, round + 1, evenScore, oddScore, evenRemaining - 1,
                oddRemaining, kicks + 1);
    }
  }
  return kicks;
}
int main() {
  int t;
  cin >> t;
  vector<string> sv(t);
  for (int i = 0; i < t; i++) cin >> sv[i];
  for (int i = 0; i < t; i++) cout << dp(sv[i], 1, 0, 0, 5, 5, 0) << endl;
  return 0;
}
