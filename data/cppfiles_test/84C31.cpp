#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    cout << s / (n / 2 + 1);
    cout << "\n";
  }
}
