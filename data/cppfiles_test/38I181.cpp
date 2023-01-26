#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 998244353;
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  } else {
    return -1;
  }
}
ll power(ll x, ll y) {
  ll res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
const int N = 100000;
void solve() {
  ll n;
  cin >> n;
  if (n <= 10) {
    if (n <= 6) {
      cout << 15 << endl;
    } else if (n <= 8) {
      cout << 20 << endl;
    } else {
      cout << 25 << endl;
    }
    return;
  }
  if (n % 10 == 0 || n % 10 == 9) {
    cout << 25 * ll(ceil(n / 10.0)) << endl;
  } else if (n % 10 <= 2) {
    cout << 30 + 25 * (n / 10 - 1) << endl;
  } else if (n % 10 <= 6) {
    cout << 15 + 25 * (n / 10) << endl;
  } else {
    cout << 20 + 25 * (n / 10) << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
