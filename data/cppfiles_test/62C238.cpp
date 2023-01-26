#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, q;
  scanf("%d", &t);
  for (q = 1; q <= t; q++) {
    long long int n, i, ans = -2;
    cin >> n;
    long long int ar[n + 5];
    for (i = 0; i < n; i++) {
      cin >> ar[i];
    }
    if (ar[0] == 1) {
      cout << n + 1 << " ";
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
    } else if (ar[n - 1] == 0) {
      for (int i = 1; i <= n + 1; i++) {
        cout << i << " ";
      }
    } else {
      for (int i = 1; i < n; i++) {
        if (ar[i] and ar[i - 1] == 0) {
          ans = i;
          break;
        }
      }
      if (ans > -1) {
        for (int i = 0; i < n; i++) {
          if (ans == i) cout << n + 1 << " ";
          cout << i + 1 << " ";
        }
      } else
        cout << "-1";
    }
    cout << endl;
  }
  return 0;
}
