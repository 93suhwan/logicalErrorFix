#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long mod = 1000000007;
  long long arr[200001];
  arr[0] = 1;
  long long ans = 1;
  for (long long i = 1; i < 200001; i++) {
    ans = i * arr[i - 1];
    ans = ans % mod;
    arr[i] = ans;
  }
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    n *= 2;
    long long anss = arr[n] / 2;
    cout << anss << endl;
  }
}
