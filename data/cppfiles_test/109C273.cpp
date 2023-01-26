#include <bits/stdc++.h>
using namespace std;
long long tc, ans;
string s;
void pt() {
  long long n;
  cin >> n;
  cin >> s;
  ans = 0;
  long long nz = 0;
  for (long long i = 0; i < s.size(); i++) {
    ans += (long long)s[i] - 48;
    if (s[i] != '0' && i != s.size() - 1) nz++;
  }
  cout << ans + nz << endl;
}
signed main() {
  cin >> tc;
  for (long long i = 1; i <= tc; i++) {
    pt();
  }
}
