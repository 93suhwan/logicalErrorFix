#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int z = 0, o = 0;
    vector<long long int> v(n);
    for (long long int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (long long int i = 0; i < n / 2; i++) {
      cout << v[n - i - 1] << " " << v[0] << endl;
    }
  }
}
