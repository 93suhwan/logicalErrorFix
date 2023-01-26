#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s = "";
    while (k) {
      s = to_string(k & 1) + s;
      k >>= 1;
    }
    long long ans = 0;
    for (int i = 0; i < s.size(); i++) {
      ans = ans * n + (s[i] - '0');
      ans %= (long long)1e9 + 7;
    }
    cout << ans << endl;
  }
}
