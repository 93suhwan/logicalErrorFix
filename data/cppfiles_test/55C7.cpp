#include <bits/stdc++.h>
long long mod = 1e9 + 7;
using namespace std;
int main() {
  int k;
  cin >> k;
  vector<long long> a(k);
  if (k == 1) {
    cout << 6;
    return 0;
  }
  a[1] = 4;
  for (int i = 2; i < k; i++) {
    a[i] = (a[i - 1] * a[i - 1] * 4) % mod;
  }
  cout << (a[k - 1] * a[k - 1] * 6) % mod << endl;
}
