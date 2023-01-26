#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    long long int n, k, q, i, j, a, b, c, x, y, m, count = 0, sum = 0, pro = 1,
                                                   count1 = 0, flag = 0;
    string s;
    n = 7;
    vector<long long int> arr(n);
    for (i = 0; i < n; i++) cin >> arr[i];
    ;
    a = arr[6] - arr[5];
    k = 1;
    for (i = 0; i < 5; i++) {
      if (k && arr[i] == a) {
        k--;
        continue;
      }
      for (j = i + 1; j < 5; j++) {
        b = arr[i];
        c = arr[j];
        if (arr[5] == (b + c) && arr[6] == (a + b + c)) {
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    cout << a << " " << b << " " << c << "\n";
  }
}
