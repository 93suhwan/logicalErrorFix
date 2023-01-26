#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long ans = (r / 2) + 1;
    if (ans < l) {
      ans = l;
    }
    cout << (long long)r % ans << endl;
  }
  return 0;
}
