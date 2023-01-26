#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int T;
int a[maxn];
void solve() {
  for (int i = 1; i <= 3; ++i) cin >> a[i];
  int sum = a[1] + a[2] + a[3];
  int maxp;
  if (a[2] > a[3])
    maxp = a[2];
  else
    maxp = a[3];
  if (maxp < a[1]) maxp = a[1];
  if (sum - maxp >= maxp)
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
