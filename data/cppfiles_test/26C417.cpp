#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int dp1[15], dp2[15], op1[15], op2[15];
int main() {
  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 6; i++) dp1[i] = 0, dp2[i] = 0, op1[i] = 0, op2[i] = 0;
    string s;
    cin >> s;
    for (int p = 0; p < s.size(); p++) {
      if (p % 2 == 0) {
        int i = (p + 1) / 2;
        if (s[p] == '1')
          dp1[i + 1] += dp1[i] + 1, dp2[i + 1] += dp2[i] + 1;
        else if (s[p] == '0')
          dp1[i + 1] = dp1[i], dp2[i + 1] = dp2[i];
        else
          dp1[i + 1] += dp1[i] + 1, dp2[i + 1] = dp2[i];
      } else {
        int i = p / 2;
        if (s[p] == '1')
          op1[i + 1] += op1[i] + 1, op2[i + 1] += op2[i] + 1;
        else if (s[p] == '0')
          op1[i + 1] = op1[i], op2[i + 1] = op2[i];
        else
          op1[i + 1] += op1[i] + 1, op2[i + 1] = op2[i];
      }
    }
    int ma = 10;
    for (int i = 1; i <= 5; i++) {
      if (dp1[i] - op2[i - 1] > 5 - i + 1)
        ma = min(ma, 2 * i - 1);
      else if (dp1[i] - op2[i] > 5 - i)
        ma = min(ma, 2 * i);
      if (op1[i - 1] - dp2[i] > 5 - i)
        ma = min(ma, 2 * i - 1);
      else if (op1[i] - dp2[i] > 5 - i)
        ma = min(ma, 2 * i);
    }
    printf("%d\n", ma);
  }
}
