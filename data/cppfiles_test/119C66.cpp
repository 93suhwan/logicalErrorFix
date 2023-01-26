#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    long long int sum = accumulate(a, a + n, 0);
    if (sum % n == 0) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
  return 0;
}
