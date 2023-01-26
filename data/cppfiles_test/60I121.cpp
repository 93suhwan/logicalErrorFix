#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a[105];
    long long maxx = -2e9;
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] > maxx) {
        maxx = a[i];
      }
    }
    long long minn = 2e9;
    for (int i = 1; i <= n; i++) {
      long long ans = a[i] & maxx;
      minn = min(minn, ans);
    }
    cout << minn << endl;
  }
  return 0;
}
