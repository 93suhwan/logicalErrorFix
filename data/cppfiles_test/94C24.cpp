#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
void solve() {
  string s;
  cin >> s;
  long long m = (int)(s.size());
  vector<long long> retu;
  for (long long i = 0; i < (m); i++) retu.emplace_back(s[i] - '0');
  long long ans = 0;
  for (long long bit = 0; bit < ((1 << m)); bit++) {
    vector<long long> now = retu;
    bool flag = true;
    for (long long i = 0; i < (m); i++) {
      if ((bit >> i) & 1) {
        if (i < 2)
          flag = false;
        else {
          if (retu[i - 2] == 0 and !((bit >> (i - 2)) & 1)) flag = false;
        }
      }
    }
    if (!flag)
      continue;
    else {
      for (int i = m - 1; i >= 0; i--) {
        if ((bit >> i) & 1) {
          now[i] += 10;
        }
      }
      for (int i = m - 1; i >= 0; i--) {
        if ((bit >> i) & 1) {
          now[i - 2]--;
        }
      }
      long long res = 1;
      for (long long i = 0; i < (m); i++) {
        if (now[i] >= 10)
          res *= 19 - now[i];
        else
          res *= now[i] + 1;
      }
      ans += res;
    }
  }
  cout << ans - 2 << endl;
}
int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
