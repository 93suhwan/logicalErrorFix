#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int a1 = n / 3, a2;
    if ((n - n / 3) & 1) ++a1;
    a2 = (n - n / 3) / 2;
    cout << a1 << ' ' << a2 << '\n';
  }
  return 0;
}
