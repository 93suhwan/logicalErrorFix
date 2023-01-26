#include <bits/stdc++.h>
using namespace std;
vector<int> arr(40001);
int j = 0;
void solve() {
  int n;
  cin >> n;
  int k;
  if (j * j < n) {
    while (j * j < n) {
      j++;
      arr[j] = j * j;
    }
    k = j;
  } else {
    k = upper_bound(arr.begin(), arr.end(), n) - arr.begin();
  }
  long long x, y, z;
  x = arr[k];
  y = arr[k] - k + 1;
  z = arr[k] - 2 * k + 2;
  if (n > y) {
    cout << k << ' ' << arr[k] - n + 1 << endl;
  } else if (n < y) {
    cout << n - z + 1 << ' ' << k << endl;
  } else {
    cout << k << ' ' << k << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
