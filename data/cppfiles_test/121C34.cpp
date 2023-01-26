#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long oz = 0, zo = 0, sum1 = 0, o = 0, z = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '0')
        oz++;
      else if (a[i] == '1')
        o++;
      if (a[i] == '0' && b[i] == '1')
        zo++;
      else if (a[i] == '0')
        z++;
    }
    long long ans = INT_MAX;
    if (zo == oz) {
      ans = min(oz + oz, ans);
    }
    if (o == z + 1) {
      ans = min(ans, o + z);
    }
    if (ans == INT_MAX)
      cout << -1 << "\n";
    else
      cout << ans << "\n";
  }
}
