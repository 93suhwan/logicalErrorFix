#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int j = 0, part = 0;
    for (j = 0; j < n - 1; j++) {
      while (a[j] < a[j + 1]) {
        j++;
      }
      part++;
    }
    if (a[n - 1] < a[n - 2]) {
      part++;
    }
    if (part <= k) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
