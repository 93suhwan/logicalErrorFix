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
int ask(int x) {
  cout << "?";
  for (int i = 1; i <= n; i++)
    if (ans[i])
      cout << " " << n;
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
  for (int i = 1; i < n; i++) ans[ask(1)] = i;
  cout << "!";
  for (int i = 1; i <= n; i++) cout << " " << (ans[i] == 0 ? n : ans[i]);
  cout << '\n';
  cout.flush();
  return 0;
}
