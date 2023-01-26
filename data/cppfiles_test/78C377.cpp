#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long ans = r % l;
    long long temp = (r + 1ll) / 2ll;
    if (temp < l) {
      temp = 0;
    } else {
      temp = temp - 1;
    }
    cout << max(temp, ans) << "\n";
  }
}
