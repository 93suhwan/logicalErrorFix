#include <bits/stdc++.h>
using namespace std;
int w = 1000000007;
bool comparator(pair<long long, long long> p1, pair<long long, long long> p2) {
  return (p1.second < p2.second);
}
long long power(long long n) {
  if (n == 1) {
    return 2;
  }
  if (n == 0) {
    return 1;
  }
  long long ans = 1;
  if (n % 2) {
    ans *= 2;
  }
  ans *= (power(n / 2) * power(n / 2));
  return ans;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long c1 = 0, c0 = 0;
    long long* arr = new long long[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] == 1) {
        c1++;
      }
      if (arr[i] == 0) {
        c0++;
      }
    }
    if (c1 == 0) {
      cout << 0 << endl;
    } else {
      long long ans = 1;
      cout << ((1 << c0) % w) * (c1 % w) % w << endl;
    }
  }
}
