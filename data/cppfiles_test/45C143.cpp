#include <bits/stdc++.h>
using namespace std;
long long int powerMod(long long int a, long long int b, long long int m) {
  long long int result = 1;
  while (b > 0) {
    if (b & 1) result = (result * a) % m;
    a = (a * a) % m;
    b /= 2;
  }
  return result;
}
long long int power(long long int a, long long int b) {
  long long int result = 1;
  while (b > 0) {
    if (b & 1) result *= a;
    a *= a;
    b /= 2;
  }
  return result;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> arr;
    bool ok = true;
    long long int prev = -1;
    for (int i = 0; i < n; ++i) {
      long long int x;
      cin >> x;
      if (i == 0)
        prev = x;
      else {
        if (x == 0 && prev == 0) ok = false;
        prev = x;
      }
      arr.push_back(x);
    }
    long long int ans = 1;
    if (ok) {
      for (int i = 0; i < n; ++i) {
        if (i == 0) {
          if (arr[i]) ans += 1;
        } else {
          if (arr[i]) {
            if (arr[i - 1])
              ans += 5;
            else
              ans += 1;
          }
        }
      }
      cout << ans << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
