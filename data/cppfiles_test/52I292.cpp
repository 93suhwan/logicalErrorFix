#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) sum += a[i];
    double ans = ((double)sum / (double)(n - 1)) + a[n - 1];
    cout << ans << endl;
  }
}
