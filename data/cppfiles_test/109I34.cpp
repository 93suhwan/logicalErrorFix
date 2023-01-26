#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 0;
  cin >> t;
  while (t--) {
    long long n = 0;
    cin >> n;
    long long ans = 0;
    string x;
    cin >> x;
    for (int i = 0; i < x.length() - 1; i++) {
      ans = ans + 1 + (x[i] - '0');
    }
    ans += (x[x.length() - 1] - '0');
    cout << ans << '\n';
  }
  return 0;
}
