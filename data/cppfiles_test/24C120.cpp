#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = (int)2e5 + 3;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int d = n % 10;
    n /= 10;
    if (d == 9)
      cout << n + 1 << "\n";
    else
      cout << n << "\n";
  }
  return 0;
}
