#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 10;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int l, r;
    cin >> l >> r;
    int a = max(l, r / 2 + 1);
    cout << r % a << '\n';
  }
  return 0;
}
