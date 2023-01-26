#include <bits/stdc++.h>
using namespace std;
int v[100001];
int n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << fixed << setprecision(10);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    int max = v[0], s = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] > max) {
        max = v[i];
      }
      s += v[i];
    }
    cout << 1.0 * (s - max) / (n - 1) + max << '\n';
  }
  return 0;
}
