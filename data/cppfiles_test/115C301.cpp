#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926536;
const int mod = 1e9 + 7;
const int inf = INT_MAX;
const long long modt = 998244353;
long long Pow(long long a, long long b) {
  if (b == 0) return (long long)1;
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
bool isValid(long long n, long long h, long long arr[], long long mid) {
  long long x = mid;
  for (int i = 1; i < n; i++) x += min(arr[i] - arr[i - 1], mid);
  return (x >= h);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    long long s = 1, e = h;
    while (s <= e) {
      long long mid = s + (e - s) / 2;
      if (isValid(n, h, arr, mid))
        e = mid - 1;
      else
        s = mid + 1;
    }
    cout << s << '\n';
  }
}
