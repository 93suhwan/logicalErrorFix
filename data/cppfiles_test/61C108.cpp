#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    vector<long long> veca(n, 0);
    vector<long long> vecb(n, 0);
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      veca[--a[i]]++;
      vecb[--b[i]]++;
    }
    long long ans = (n * (n - 1) * (n - 2)) / 6;
    for (int i = 0; i < n; i++) {
      ans = ans - (veca[a[i]] - 1) * (vecb[b[i]] - 1);
    }
    cout << ans << endl;
  }
}
