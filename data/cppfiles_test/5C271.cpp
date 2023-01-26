#include <bits/stdc++.h>
using namespace std;
long long n, i, ans;
string pm, pk;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    ans = 0;
    cin >> n >> pm >> pk;
    pm = "0" + pm;
    pk = "0" + pk;
    for (i = 1; i <= n; i++) {
      if (pm[i] == '0' && pk[i] == '1') {
        pm[i] = '2';
        ans++;
      } else if (i > 1 && pk[i] == '1' && pm[i - 1] == '1') {
        pm[i - 1] = '2';
        ans++;
      } else if (i < n && pk[i] == '1' && pm[i + 1] == '1') {
        pm[i + 1] = '2';
        ans++;
      }
    }
    cout << ans << endl;
  }
}
