#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int maxVal = 0;
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] > maxVal) {
        res++;
        maxVal = a[i];
      }
    }
    cout << res - 1 << "\n";
  }
  return 0;
}
