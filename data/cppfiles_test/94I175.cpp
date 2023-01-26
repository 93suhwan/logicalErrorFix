#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int a[12];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
      long long temp = pow(10, a[i + 1] - a[i]) - 1;
      if (k - temp <= 0) {
        sum += (k + 1) * pow(10, a[i]);
        flag = 1;
      } else {
        sum += temp * pow(10, a[i]);
        k -= temp;
      }
    }
    if (flag == 1) {
      cout << sum << endl;
    } else {
      cout << (k + 1) * (long long)pow(10, a[n - 1]) + sum << endl;
    }
  }
}
