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
    long long ans = 1;
    ans *= n;
    ans *= n - 1;
    ans *= n - 2;
    ans /= 6;
    for (int i = 1; i <= n; i++) {
      if (v1[a[i]] >= 2 && v2[b[i]] >= 2) {
        long long tmp = v1[a[i]] - 1;
        tmp *= (v2[b[i]] - 1);
        sum += tmp;
      }
    }
    cout << ans - sum << endl;
  }
  return 0;
}
