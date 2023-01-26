#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e9;
long long powermod(long long A, long long B) {
  long long ret = 1;
  A %= MAX;
  B %= MAX - 1;
  while (B > 0) {
    if (B % 2 > 0) ret = ret * A % MAX;
    A = A * A % MAX;
    B /= 2;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t, x0, n;
  cin >> t;
  while (t--) {
    cin >> x0 >> n;
    vector<long long> a;
    long long ans = x0;
    for (long long i = 0; i < 4; i++) {
      long long min = i + 1;
      if (ans & 1)
        ans += min;
      else
        ans -= min;
      a.push_back(ans);
    }
    long long temp = n % 4;
    if (temp == 2 or temp == 0) {
      if (temp == 0) temp += 4;
      cout << a[temp - 1] << endl;
    } else {
      if (temp == 1) {
        n--;
        long long dem = n / 4.0;
        if (x0 & 1)
          cout << a[temp - 1] + dem * 4 << endl;
        else
          cout << a[temp - 1] - dem * 4 << endl;
      } else {
        n--;
        long long dem = n / 4.0;
        if (x0 & 1)
          cout << a[temp - 1] - dem * 4 << endl;
        else
          cout << a[temp - 1] + dem * 4 << endl;
      }
    }
  }
  return 0;
}
