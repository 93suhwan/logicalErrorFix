#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1) {
      cout << 0;
      cout << "\n";
      continue;
    }
    vector<long long> x(n);
    vector<long long> y(n);
    vector<long long> prex(n);
    vector<long long> prey(n);
    for (long long i = 0; i < n; i++) cin >> x[i];
    for (long long i = 0; i < n; i++) cin >> y[i];
    prex[n - 1] = x[n - 1];
    prey[0] = y[0];
    for (long long i = 1; i < n; i++) prey[i] = prey[i - 1] + y[i];
    for (long long i = n - 2; i >= 0; i--) prex[i] = prex[i + 1] + x[i];
    long long mn = 999999999999999999;
    for (long long i = 0; i < n; i++) {
      if (i == 0)
        mn = min(mn, prex[i + 1]);
      else if (i == n - 1)
        mn = min(mn, prey[i - 1]);
      else
        mn = min(mn, max(prex[i + 1], prey[i - 1]));
    }
    cout << mn;
    cout << "\n";
  }
  return 0;
}
