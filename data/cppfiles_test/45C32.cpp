#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    long long int h = 1;
    for (long long int i = 0; i < n; i++) {
      if (a[i]) {
        if (i > 0 && a[i - 1]) {
          h += 5;
        } else
          h++;
      } else {
        if (i > 0 && !a[i - 1]) {
          h = -1;
          break;
        }
      }
    }
    cout << h << "\n";
  }
  return 0;
}
