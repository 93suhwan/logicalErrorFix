#include <bits/stdc++.h>
using namespace std;
int vis[300011];
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, s0, s1, str0, str1, str2;
    cin >> s;
    str2 = s;
    int sum2 = 0;
    for (int i = 0; i < str2.size(); i++) {
      sum2 = sum2 * 10;
      sum2 = sum2 + (str2[i] - '0');
    }
    if (sum2 < 10) {
      printf("%d\n", sum2 - 1);
      continue;
    } else if (sum2 < 100 && sum2 >= 10) {
      printf("%d\n", sum2 % 10 * 2);
      continue;
    }
    int ans0 = 1, ans1 = 1, sum0 = 0, sum1 = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (i % 2 == 0) {
        s0 += s[i];
        str0 += '0';
      } else {
        s1 += s[i];
        str1 += '0';
      }
    }
    reverse(s0.begin(), s0.end());
    reverse(s1.begin(), s1.end());
    for (int i = 0; i < s0.size(); i++) {
      sum0 = sum0 * 10;
      sum0 = sum0 + (s0[i] - '0');
    }
    for (int i = 0; i < s1.size(); i++) {
      sum1 = sum1 * 10;
      sum1 = sum1 + (s1[i] - '0');
    }
    ans1 = sum1 + 1;
    ans0 = sum0 + 1;
    long long ans = ans0 * ans1 - 2;
    printf("%d\n", ans);
  }
  return 0;
}
