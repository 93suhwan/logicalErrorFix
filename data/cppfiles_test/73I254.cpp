#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n;
int a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] != i) res = max(res, abs(a[i] - i) + 1);
    }
    cout << res << endl;
  }
  return 0;
}
