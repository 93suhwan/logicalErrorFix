#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cout << i + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
