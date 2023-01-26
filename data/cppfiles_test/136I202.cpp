#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> mp;
vector<long long int> v;
set<long long int> st;
map<long long int, long long int>::iterator it;
long long int a[500005];
long long int b[500005];
long long int ans[500005];
string ss[500005];
int main() {
  int i, j, k;
  long long int res, n, m, t, gc, gcc;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int bsum = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      bsum += a[i];
    }
    long long int sum = (n * (n + 1)) / 2;
    if (bsum % sum != 0) {
      cout << "NO" << '\n';
    } else {
      int fll = 0;
      bsum = bsum / sum;
      for (i = 1; i < n; i++) {
        b[i - 1] = a[i] - a[i - 1];
      }
      b[n - 1] = a[0] - a[n - 1];
      for (i = 0; i < n; i++)
        for (i = 0; i < n; i++) {
          long long int as = bsum - b[i];
          if (as % n != 0 || as == 0) fll = 1;
          ans[i] = (bsum + b[i]) / n;
        }
      if (fll == 1)
        cout << "NO" << '\n';
      else {
        cout << "YES" << '\n';
        for (i = 0; i < n; i++) cout << ans[i] << " ";
        cout << '\n';
      }
    }
  }
  return 0;
}
