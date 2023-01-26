#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int a[n];
    long long int s = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    s -= k;
    sort(a, a + n);
    long long int ans = s, c = 0;
    if (n == 1) {
      cout << max((long long int)0, s) << "\n";
      continue;
    }
    long long int i = n - 1;
    while (i > 0) {
      s -= (a[i] - a[0]);
      c++;
      ans = min(ans, c + max((s + n - i) / (n - i + 1), (long long int)0));
      i--;
    }
    cout << max(ans, (long long int)0) << "\n";
  }
}
