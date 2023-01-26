#include <bits/stdc++.h>
using namespace std;
int a[200002];
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int vmax = -1e9;
    for (int i = 1; i <= n; i++) {
      vmax = max(vmax, a[i] - a[i - 1]);
    }
    cout << vmax << '\n';
  }
}
