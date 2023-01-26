#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265359;
void nCr() {
  vector<vector<long long>> fac(1001, vector<long long>(1001, 1));
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        fac[i][j] = 1;
      else
        fac[i][j] = (fac[i - 1][j - 1] + fac[i - 1][j]) % 1000000007;
    }
  }
}
long long sub(long long a, long long b) {
  return ((a + 1000000007) % 1000000007 - (b + 1000000007) % 1000000007 +
          1000000007) %
         1000000007;
}
long long mul(long long a, long long b) {
  return ((a + 1000000007) % 1000000007 * (b + 1000000007) % 1000000007) %
         1000000007;
}
long long sum(long long a, long long b) {
  return ((a + 1000000007) % 1000000007 + (b + 1000000007) % 1000000007) %
         1000000007;
}
long long apowb(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 != 0) ans = mul(ans, a);
    a = mul(a, a);
    b = b / 2;
  }
  return ans;
}
void solve() {
  string s;
  cin >> s;
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == 'b' && s[i - 1] == 'a')
      cnt1++;
    else if (s[i] == 'a' && s[i - 1] == 'b')
      cnt2++;
  }
  if (cnt1 == cnt2) {
    cout << s << endl;
    return;
  } else {
    if (s[0] == 'a')
      s[0] = 'b';
    else
      s[0] = 'a';
  }
  cout << s << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
