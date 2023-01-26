#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int a[12];
long long fastpow(long long a, long long b) {
  long long sum = 1;
  while (b) {
    if (b & 1) sum *= a;
    a *= a;
    b >>= 1;
  }
  return sum;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
      long long temp = fastpow(10, a[i + 1] - a[i]) - 1;
      if (k - temp < 0) {
        sum += (k + 1) * fastpow(10, a[i]);
        flag = 1;
        break;
      } else {
        sum += temp * fastpow(10, a[i]);
        k -= temp;
      }
    }
    if (flag == 1)
      cout << sum << endl;
    else {
      sum += (k + 1) * fastpow(10, a[n - 1]);
      cout << sum << endl;
    }
  }
}
