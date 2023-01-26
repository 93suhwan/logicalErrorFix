#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int x = max((r + 1) / 2, l);
    cout << min((x * 2 - 1), r) % x << '\n';
  }
  return 0;
}
