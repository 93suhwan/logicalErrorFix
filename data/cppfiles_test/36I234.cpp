#include <bits/stdc++.h>
using namespace std;
int t, n, a[111], sum, ind;
bool pr[22222222];
void sieve() {
  for (int i = 1; i <= 2000000; i++) pr[i] = 1;
  for (int i = 2; i * i <= 2000000; i++) {
    if (pr[i]) {
      for (int j = i * i; j <= 2000000; j += i) {
        pr[j] = 0;
      }
    }
  }
}
int main() {
  cin >> t;
  sieve();
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    if (!pr[sum]) {
      cout << n << endl;
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] & 1) {
        ind = i;
        break;
      }
    }
    cout << n - 1 << endl;
    for (int i = 0; i < n; i++)
      if (i != ind) cout << i + 1 << " ";
    cout << endl;
  }
  return 0;
}
