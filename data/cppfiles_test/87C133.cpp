#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, i, j = 0, s = 0, k = 0, mini = INT_MAX, flag = 1;
    cin >> n;
    long long int a[n + 1];
    for (i = 1; i <= n; i++) {
      cin >> a[i];
    }
    s = 1;
    for (i = 1; i <= n; i++) {
      if (a[i] > s) {
        k = k + a[i] - s;
        s = a[i];
      }
      s++;
    }
    cout << k << endl;
  }
}
