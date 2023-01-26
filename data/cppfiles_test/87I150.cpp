#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ar[n + 1];
    map<int, int> m;
    for (int i = 1; i <= n; i++) {
      cin >> ar[i];
      m[ar[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (ar[i] > m[ar[i]]) {
        int p = ar[i] - m[ar[i]];
        ans += p;
        for (int j = i; j <= n; j++) {
          m[ar[j]] += p;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
