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
  if (n <= 6) {
    cout << 15 << endl;
    return;
  } else if (n <= 8) {
    cout << 20 << endl;
    return;
  } else if (n <= 10) {
    cout << 25 << endl;
    return;
  }
  if (n % 6 == 0) {
    cout << 15 * (n / 6) << endl;
  } else if (n % 8 == 0) {
    cout << 20 * (n / 8) << endl;
  } else if (n % 10 == 0) {
    cout << 25 * (n / 10) << endl;
  } else {
    if (n % 10 == 1 || n % 10 == 2) {
      cout << 25 * (n / 10 - 1) + 30 << endl;
    } else if (n % 10 == 6 || n % 10 == 5) {
      cout << 25 * (n / 10) + 15 << endl;
    } else if (n % 10 == 3 || n % 10 == 4) {
      cout << 35 + 25 * (n / 10 - 1) << endl;
    } else if (n % 10 == 7 || n % 10 == 8) {
      cout << 25 * (n / 10) + 20 << endl;
    } else {
      cout << 25 * (n / 10 + 1) << endl;
    }
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
