#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, INF = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    cout << r % max(l, r / 2 + 1) << "\n";
  }
}
