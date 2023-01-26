#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long res = 0;
    int d = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] > i + d) {
        res += a[i] - i - d;
        d += a[i] - d - i;
      }
    cout << res << endl;
  }
  return 0;
}
