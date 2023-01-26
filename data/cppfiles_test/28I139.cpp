#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a[4];
    long long mixn = 100000001, next, ans = 0, sum = 0;
    for (int i = 1; i <= 3; i++) {
      cin >> a[i];
      sum += a[i];
    }
    cout << (sum % 2 + 1) % 2 << endl;
  }
}
