#include <bits/stdc++.h>
using namespace std;
int t;
int d[1000010];
int main() {
  cin >> t;
  while (t--) {
    int n, m = -(1 << 30);
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> d[i];
    }
    sort(d + 1, d + n + 1);
    for (int i = n; i >= 1; i--) {
      d[i] -= d[i - 1];
      m = max(m, d[i]);
    }
    cout << m << endl;
  }
  return 0;
}
