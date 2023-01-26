#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a = 0;
  cin >> a;
  while (a--) {
    int q, w;
    cin >> q >> w;
    if (q == w && q == 0)
      cout << 0 << endl;
    else if (q == w)
      cout << 1 << endl;
    else if ((max(q, w) - min(q, w)) % 2 == 0) {
      cout << 2 << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
