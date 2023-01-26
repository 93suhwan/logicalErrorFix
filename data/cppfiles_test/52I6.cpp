#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    double sum = 0;
    double la = INT_MIN;
    double x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      sum += x;
      la = max(la, x);
    }
    double ans;
    ans = (sum - la);
    ans /= double(n - 1);
    ans += la;
    cout << ans << endl;
  }
}
