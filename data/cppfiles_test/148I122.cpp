#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int w, h, k, p, x;
    cin >> w >> h;
    cin >> k;
    p = k;
    long long int a[k + 123];
    for (int i = 0; i < k; i++) cin >> a[i];
    cin >> k;
    for (int i = 0; i < k; i++) cin >> x;
    cin >> k;
    long long int b[k + 123];
    long long int q = k;
    for (int i = 0; i < k; i++) cin >> b[i];
    cin >> k;
    for (int i = 0; i < k; i++) cin >> x;
    long long int m, n;
    sort(a, a + p);
    sort(b, b + q);
    m = (a[p - 1] - a[0]) * h;
    n = (b[q - 1] - b[0]) * w;
    cout << max(m, n) << "\n";
  }
  return 0;
}
