#include <bits/stdc++.h>
using namespace std;
long long a[200005], b[200005];
long long v1[200005], v2[200005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) v1[i] = 0, v2[i] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      v1[a[i]]++;
      v2[b[i]]++;
    }
    long long ans = n * (n - 1) * (n - 2);
    ans /= 6;
    for (int i = 1; i <= n; i++) {
      if (v1[i] >= 3) {
        long long tmp = v1[i] * (v1[i] - 1) * (v1[i] - 2);
        tmp /= 6;
        ans -= tmp;
      }
      if (v2[i] >= 3) {
        long long tmp = v2[i] * (v2[i] - 1) * (v2[i] - 2);
        tmp /= 6;
        ans -= tmp;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (v1[a[i]] >= 2 && v2[b[i]] >= 2) {
        long long tmp = v1[a[i]] - 1;
        tmp *= v2[b[i]] - 1;
        ans -= tmp;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
