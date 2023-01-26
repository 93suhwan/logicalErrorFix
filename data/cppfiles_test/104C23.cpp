#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) {
    long long int n, m;
    cin >> n >> m;
    long long int sum1 = 0, sum2 = 0;
    long long int a[n], b[n], mina[n], mi = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      sum1 += a[i];
      sum2 += b[i];
      mina[i] = max(0LL, m - b[i]);
      mi += mina[i];
      a[i] = min(a[i], m);
    }
    long long int ans = sum1 - sum2 + (n * m);
    long long int x = ans - 2LL * mi;
    for (int i = 0; i < n; i++) {
      if (x <= 0) break;
      long long int temp = min(2LL * (a[i] - mina[i]), x);
      temp /= 2;
      mina[i] += temp;
      x -= 2LL * temp;
    }
    cout << abs(x) << "\n";
    for (int i = 0; i < n; i++) cout << mina[i] << " " << m - mina[i] << "\n";
  }
  return 0;
}
