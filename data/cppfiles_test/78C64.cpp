#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b;
  cin >> a >> b;
  if (b / 2 >= a)
    cout << (b % (b / 2 + 1));
  else
    cout << b % a;
  cout << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
