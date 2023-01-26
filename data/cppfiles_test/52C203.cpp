#include <bits/stdc++.h>
using namespace std;
long long fast_pow(int a, int b) {
  if (b == 0) return 1;
  if (b % 2 == 1) return (fast_pow(a, b - 1) * a) % 1000000007;
  long long tmp = fast_pow(a, b / 2);
  return (tmp * tmp) % 1000000007;
}
long long upper_bound_power(int b) {
  int tmp = 1, i = 0;
  while (tmp <= b) {
    i++;
    tmp = fast_pow(2, i);
  }
  return i - 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k, i = 0, sum = 0;
    cin >> n >> k;
    while (k > 0) {
      if (k % 2) {
        sum += fast_pow(n, i);
        sum %= 1000000007;
      }
      i++;
      k /= 2;
    }
    cout << sum << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
