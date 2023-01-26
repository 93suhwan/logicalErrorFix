#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long int INF = 0x3f3f3f3f3f3f3f3f;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ar[n + 2], ans[n + 2];
    long long int sum = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> ar[i];
      sum += ar[i];
    }
    long long int num = (n * (n + 1)) / 2;
    if (sum % num)
      cout << "NO" << '\n';
    else {
      sum /= num;
      long long int f = 0;
      for (long long int i = 0; i < n; i++) {
        long long int dif = ar[i] - ar[(n + i - 1) % n];
        dif = sum - dif;
        if (dif <= 0 || (dif % n)) {
          f = 1;
          cout << "NO" << '\n';
          break;
        }
        dif /= n;
        ans[i] = dif;
      }
      if (!f) {
        cout << "YES" << '\n';
        for (long long int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << '\n';
      }
    }
  }
  return 0;
}
