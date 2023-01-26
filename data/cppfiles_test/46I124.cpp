#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int mxm = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    vector<long long int> a, b;
    for (i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      a.push_back(x);
    }
    b = a;
    sort((b).begin(), (b).end());
    long long int mx1 = b[n - 1];
    long long int mx2 = b[n - 2];
    long long int x = 1, y = 0;
    for (i = n - 1; i > 0; i--) {
      if (a[i] < a[i - 1]) {
        x++;
      } else {
        y = max(y, x);
        x = 1;
      }
    }
    y = max(y, x);
    cout << (y - 1) << endl;
  }
  return 0;
}
