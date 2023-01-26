#include <bits/stdc++.h>
using namespace std;
const int N = 4000006;
using ll = long long;
ll f[N];
int main() {
  ll n, m;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++) f[i] = 0;
    f[1] = 1;
    ll sum = 0;
    ll sum2 = 0;
    for (int i = 2; i <= n; i++) {
      (f[i] += sum) %= m;
      (f[i] += sum2) %= m;
      (f[i] += f[i - 1]) %= m;
      (sum += f[i - 1]) %= m;
      (f[i] += 1) %= m;
      sum2 = (f[i] - sum + m);
      sum2 %= m;
      for (int j = 2; j * i <= n; j++) {
        (f[j * i] += f[i] - f[i - 1]) %= m;
      }
    }
    cout << f[n] << endl;
  }
  return 0;
}
