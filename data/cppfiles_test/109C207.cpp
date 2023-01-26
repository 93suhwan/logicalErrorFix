#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  fast();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string str;
    cin >> str;
    long long ans = 0;
    for (long long i = 0; i < n - 1; i++) {
      ans += str[i] - '0';
      if (str[i] != '0') ans += 1;
    }
    ans += str[n - 1] - '0';
    cout << ans << "\n";
  }
  return 0;
}
