#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    int n, k, a[101], sma = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n - 2 * k; i++) sma += a[i];
    for (int i = 0; i < k; i++) sma += a[n - 2 * k + i] / a[n - k + i];
    cout << sma << "\n";
  }
}
