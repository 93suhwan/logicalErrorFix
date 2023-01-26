#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long lnf = 0x7f7f7f7f7f7f7f7f;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 1e7 + 10;
int n;
int ans[110];
int ask(int x, int y, int id) {
  cout << "?";
  for (int i = 1; i <= n; i++)
    if (i == id)
      cout << " " << y;
    else
      cout << " " << x;
  cout << '\n';
  cout.flush();
  int res;
  cin >> res;
  return res;
}
int32_t main() {
  cin >> n;
  int flag = 1;
  for (int i = 1; i < n; i++) {
    int tmp = ask(1, n - i + 1, n);
    if (tmp) {
      ans[tmp] = n;
      ans[n] = i;
      flag = 0;
      break;
    }
  }
  if (flag) ans[n] = n;
  for (int i = 1; i < n; i++) ans[ask(n + 1 - i, n + 1 - ans[n], n)] = i;
  cout << "!";
  for (int i = 1; i <= n; i++) cout << " " << ans[i];
  cout << '\n';
  cout.flush();
  return 0;
}
