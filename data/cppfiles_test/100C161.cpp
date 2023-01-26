#include <bits/stdc++.h>
using namespace std;
int main() {
  int ta = 1;
  cin >> ta;
  while (ta--) {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long res = a[0];
    long long sub = a[0];
    for (int i = 1; i < n; i++) {
      long long can = a[i] - sub;
      res = max(res, can);
      sub += can;
    }
    cout << res << endl;
  }
  return 0;
}
