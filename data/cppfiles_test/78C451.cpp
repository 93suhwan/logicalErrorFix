#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  io();
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long p = r;
    long long k = max(l, r / 2 + 1);
    cout << p % k << "\n";
  }
}
