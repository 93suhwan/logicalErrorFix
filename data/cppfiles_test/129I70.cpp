#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, count = 0, flag = 0;
    cin >> n;
    long long int a[n + 1];
    for (i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
      if (a[i] != i) {
        if (a[i] > 2 * i) {
          count++;
        } else {
          flag = 1;
        }
      }
    }
    if (flag == 1) {
      cout << -1 << '\n';
    } else {
      cout << count << '\n';
    }
  }
}
