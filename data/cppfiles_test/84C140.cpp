#include <bits/stdc++.h>
using namespace std;
void file_i_o() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  file_i_o();
  long long t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    long long a = n / 2 + 1;
    long long ans = s / a;
    cout << ans << endl;
  }
  return 0;
}
