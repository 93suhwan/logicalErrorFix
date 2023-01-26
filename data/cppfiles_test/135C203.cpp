#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
const long long INF = 1e17;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long scr = 0;
    for (int i = 0; i < n - 2 * k; i++) {
      scr += a[i];
    }
    for (int i = n - 2 * k; i < n - k; i++) {
      scr += a[i] / a[i + k];
    }
    cout << scr;
    cout << '\n';
  }
  return 0;
}
