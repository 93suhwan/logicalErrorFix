#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long sum = 0;
    long long la = INT_MIN;
    long long x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      sum += x;
      la = max(la, x);
    }
    double ans;
    ans = double(sum - la);
    ans /= double(n - 1);
    ans += double(la);
    cout << fixed << setprecision(7) << ans << endl;
  }
}
