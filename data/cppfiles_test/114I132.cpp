#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n / 2; i++) {
      cout << a[0] << " " << a[n - i - 1] << endl;
    }
  }
}
