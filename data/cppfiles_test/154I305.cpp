#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int T;
int a[maxn];
void solve() {
  for (int i = 1; i <= 3; ++i) cin >> a[i];
  int sum = a[1] + a[2] + a[3];
  int maxp = max(a[1], a[2]);
  maxp = max(maxp, a[3]);
  int flag = 0;
  if (maxp == sum / 2) {
    flag = 1;
  }
  int cnt = 0;
  int bj = 0;
  if (a[1] == a[2])
    bj = 3;
  else if (a[2] == a[3])
    bj = 1;
  else if (a[1] == a[3])
    bj = 2;
  if (bj != 0 && a[bj] % 2 == 0) flag = 1;
  if (flag)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int main() {
  cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) solve();
  return 0;
}
