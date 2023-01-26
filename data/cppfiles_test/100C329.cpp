#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
    }
    if (v.size() == 1)
      cout << v[0] << endl;
    else {
      sort(v.begin(), v.end());
      long long mi = v[0];
      long long dif = mi;
      for (long long i = 1; i < n; i++) {
        v[i] = v[i] - dif;
        mi = max(mi, v[i]);
        dif += v[i];
      }
      cout << mi << endl;
    }
  }
  return 0;
}
