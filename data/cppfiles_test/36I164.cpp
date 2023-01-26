#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, sum = 0, f = 0, x = 0;
    long long int prime[] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,
                             31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
                             73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                             127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                             179, 181, 191, 193, 197, 199};
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    for (i = 0; i < 46; i++) {
      if (prime[i] == sum) {
        f = 1;
        break;
      }
    }
    if (f == 0) {
      cout << n << '\n';
      for (i = 0; i < n; i++) cout << i + 1 << ' ';
    } else {
      cout << n - 1 << '\n';
      for (i = 0; i < n; i++) {
        if (a[i] % 2 != 0 && x == 0) {
          x = 1;
          continue;
        }
        cout << i + 1 << ' ';
      }
    }
    cout << '\n';
  }
}
