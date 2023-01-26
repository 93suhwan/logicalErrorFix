#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long dp1[N];
long long dp2[N];
long long dp3[N];
long long dp4[N];
long long dp5[N];
long long dp6[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  string s;
  cin >> n >> m >> s;
  string s1 = "", s2 = "", s3 = "", s4 = "", s5 = "", s6 = "";
  long long cnt = 0;
  while (cnt < n) {
    s1 += "abc";
    s2 += "acb";
    s3 += "bac";
    s4 += "bca";
    s5 += "cba";
    s6 += "cab";
    cnt += 3;
  }
  for (long long i = 1; i <= n; i++) {
    dp1[i] = (s1[i - 1] != s[i - 1]);
    dp2[i] = (s2[i - 1] != s[i - 1]);
    dp3[i] = (s3[i - 1] != s[i - 1]);
    dp4[i] = (s4[i - 1] != s[i - 1]);
    dp5[i] = (s5[i - 1] != s[i - 1]);
    dp6[i] = (s6[i - 1] != s[i - 1]);
  }
  for (long long i = 1; i <= n; i++) {
    dp1[i] = dp1[i - 1] + dp1[i];
    dp2[i] = dp2[i - 1] + dp2[i];
    dp3[i] = dp3[i - 1] + dp3[i];
    dp4[i] = dp4[i - 1] + dp4[i];
    dp5[i] = dp5[i - 1] + dp5[i];
    dp6[i] = dp6[i - 1] + dp6[i];
  }
  while (m--) {
    long long l, r;
    cin >> l >> r;
    long long m1 = dp1[r] - dp1[l - 1];
    long long m2 = dp2[r] - dp2[l - 1];
    long long m3 = dp3[r] - dp3[l - 1];
    long long m4 = dp4[r] - dp4[l - 1];
    long long m5 = dp5[r] - dp5[l - 1];
    long long m6 = dp6[r] - dp6[l - 1];
    cout << min({m1, m2, m3, m4, m5, m6}) << endl;
  }
  return 0;
}
