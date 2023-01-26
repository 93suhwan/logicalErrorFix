#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    long long temp1 = 0;
    long long flag1 = 0;
    long long flag2 = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        temp1++;
        if (a[i] == '1') flag1++;
      } else if (a[i] == '1')
        flag2++;
    }
    long long temp2 = n - temp1;
    long long ans = LLONG_MAX;
    if (temp1 % 2 == 1 && flag1 == (temp1 / 2 + 1)) ans = min(ans, temp1);
    if (temp2 % 2 == 0 && flag2 == temp2 / 2) ans = min(ans, temp2);
    if (ans == LLONG_MAX) ans = -1;
    cout << ans << "\n";
  }
  return 0;
}
