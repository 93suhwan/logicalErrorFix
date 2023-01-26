#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long ans = r - l;
    ans /= 2;
    cout << ans << "\n";
  }
}
