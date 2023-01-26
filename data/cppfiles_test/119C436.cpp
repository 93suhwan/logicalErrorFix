#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      ll x;
      cin >> x;
      sum += x;
    }
    (sum % n == 0) ? cout << 0 : cout << 1;
    cout << endl;
  }
  return 0;
}
