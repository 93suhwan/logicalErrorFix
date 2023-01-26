#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int sum = 0;
    long long int prev = 0;
    vector<long long int> v(n);
    for (auto &i : v) cin >> i;
    bool f = 1;
    for (int i = 0; i < n - 1; i++) {
      long long int temp = pow(10, v[i + 1] - v[i]) - 1;
      if (temp < k) {
        sum += temp * (pow(10, v[i]));
        k -= temp;
      } else {
        sum += (k + 1) * (pow(10, v[i]));
        f = 0;
      }
    }
    if (f) {
      sum += (k + 1) * (pow(10, v[n - 1]));
    }
    cout << sum << "\n";
  }
  return 0;
}
