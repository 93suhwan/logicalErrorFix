#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long p = 1e-9;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
      p = max(p, a[i] * a[i - 1]);
    }
    cout << p << endl;
  }
}
