#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[300005];
int search(int l, int r, int key) {
  if (r < l) {
    return -1;
  }
  int mid = (l + r) / 2;
  if (a[mid] < key) {
    return search(mid + 1, r, key);
  } else if (a[mid] > key) {
    return search(l, mid - 1, key);
  } else {
    return mid;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s = 0;
    int a[n + 1];
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (search(1, n, a[i] % a[j]) != -1) {
          cout << a[i] << " " << a[j] << endl;
          s++;
        }
        if (s == n / 2) {
          goto gt;
        }
        if (search(1, n, a[j] % a[i]) != -1) {
          cout << a[j] << " " << a[i] << endl;
          s++;
        }
        if (s == n / 2) {
          goto gt;
        }
      }
    }
  gt:;
  }
}
