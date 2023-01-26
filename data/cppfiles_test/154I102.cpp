#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int T;
int a[maxn];
void solve() {
  for (int i = 1; i <= 3; ++i) cin >> a[i];
  if ((a[1] + a[2] + a[3]) % 2 == 0)
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
