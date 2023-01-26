#include <bits/stdc++.h>
using namespace std;
const bool testcase = 1;
const long long int mod1 = 1000000007;
const long long int mod2 = 998244353;
void solve(long long int& kes) {
  long long int n;
  cin >> n;
  long long int prt = n / 3;
  long long int x = prt, y = prt;
  long long int sum = x + 2 * y;
  if (abs(n - sum) == 1) {
    x++;
  } else if (abs(n - sum) == 2) {
    y++;
  }
  cout << x << ' ' << y << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long int t = 1;
  int T_T = 1;
  if (testcase) {
    cin >> T_T;
  }
  while (T_T--) {
    solve(t);
    t++;
  }
  return 0;
}
