#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
g:
  while (t--) {
    long long int n, sum = 1;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == 0 && a[i + 1] == 0) {
        cout << -1 << endl;
        goto g;
      }
      if (a[i] == 1 && a[i + 1] == 1) {
        sum += 5;
      } else if (a[i] == 1) {
        sum += 1;
      }
    }
    cout << sum << endl;
  }
}
