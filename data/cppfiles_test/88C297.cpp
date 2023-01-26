#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
long long i, j, n, m, k, t;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long arr[n + 5], mx = 0;
    vector<int> v;
    for (i = 0; i < n; i++) cin >> arr[i];
    if (n % 2 == 0)
      cout << "YES\n";
    else {
      for (i = 0; i < n - 1; i++) {
        if (arr[i] >= arr[i + 1]) mx = 1;
      }
      if (mx)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
