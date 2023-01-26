#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < (n); i++) cin >> a[i];
    sort((a).rbegin(), (a).rend());
    vector<long long> v(k * 2);
    long long tot = 0;
    for (int i = 0; i < (n); i++) {
      if (i < k * 2)
        v[i] = a[i];
      else
        tot += a[i];
    }
    for (int i = 0; i < (k); i++) tot += v[i + k] / v[i];
    cout << tot << endl;
  }
  return 0;
}
