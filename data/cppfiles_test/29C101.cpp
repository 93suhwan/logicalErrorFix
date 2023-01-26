#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, j, cnt0, cnt1;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    cnt0 = count(a, a + n, 0);
    cnt1 = count(a, a + n, 1);
    long long int p = pow(2, cnt0);
    cout << p * cnt1 << endl;
  }
  return 0;
}
