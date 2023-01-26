#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      s += a;
    }
    long long mn = s / n;
    long long mx = ceil((double)s / n);
    long long ugl = mx - mn;
    cout << ugl << endl;
  }
  return 0;
}
