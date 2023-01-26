#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (long long q = 0; q < t; q++) {
    long long n, k;
    cin >> n >> k;
    k++;
    vector<long long> h(n);
    for (long long i = 0; i < n; i++) {
      cin >> h[i];
    }
    vector<long long> vys;
    for (long long i = 0; i < n - 1; i++) {
      if (k == 0) break;
      int r = h[i + 1] - h[i];
      int c = 0;
      for (long long j = 0; j < r; j++) {
        c *= 10;
        c += 9;
      }
      if (k <= c) {
        vys.push_back(k);
        k = 0;
      } else {
        k -= c;
        vys.push_back(c);
      }
    }
    if (k > 0) vys.push_back(k);
    for (int i = vys.size() - 1; i >= 0; i--) cout << vys[i];
    cout << endl;
  }
  return 0;
}
