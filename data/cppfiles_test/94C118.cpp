#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7, MAXN = 2e5 + 5, oo = 3e18;
long long tc, n;
string num;
long long col[15];
long long way[100];
void aurelion_sol() {
  cin >> n;
  num = to_string(n);
  long long sz = num.size();
  long long ans = 0;
  reverse(num.begin(), num.end());
  for (int i = sz + 1; i <= 10; i++) {
    num += "0";
  }
  long long state = (1 << 8) - 1;
  for (int mask = 0; mask <= state; mask++) {
    for (int i = 0; i <= 9; i++) col[i] = 0;
    long long tmp = 1;
    bool flag = false;
    for (int i = 0; i <= 9; i++) {
      long long dig = num[i] - '0';
      long long rev = dig - col[i];
      if (mask & (1 << i)) {
        rev += 10;
        col[i + 2]++;
      }
      if (rev < 0) {
        flag = true;
        break;
      }
      tmp *= way[rev];
    }
    if (flag) continue;
    ans += tmp;
  }
  ans -= 2;
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      way[i + j]++;
    }
  }
  cin >> tc;
  while (tc--) aurelion_sol();
}
