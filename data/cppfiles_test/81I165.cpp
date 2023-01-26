#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  int n, m, l, r;
  string s;
  while (t-- > 0) {
    cin >> n >> m;
    cin >> s;
    int arr[n + 1];
    int brr[n + 1];
    brr[0] = 0;
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        if (s[i - 1] == '+') {
          arr[i] = arr[i - 1] + 1;
          brr[i] = brr[i - 1] - 1;
        } else {
          arr[i] = arr[i - 1] - 1;
          brr[i] = brr[i - 1] + 1;
        }
      } else {
        if (s[i - 1] == '-') {
          arr[i] = arr[i - 1] + 1;
          brr[i] = brr[i - 1] - 1;
        } else {
          arr[i] = arr[i - 1] - 1;
          brr[i] = brr[i - 1] + 1;
        }
      }
    }
    int l, r;
    for (int i = 0; i < m; i++) {
      cin >> l >> r;
      if (l % 2 == 1) {
        int y = arr[r] - arr[l - 1];
        if (y == 0) {
          cout << 0 << "\n";
        }
        if (abs(y) % 2 == 0) {
          cout << 2 << "\n";
        } else {
          cout << 1 << "\n";
        }
      } else {
        int y = brr[r] - brr[l - 1];
        if (y == 0) {
          cout << 0 << "\n";
        }
        if (abs(y) % 2 == 0) {
          cout << 2 << "\n";
        } else {
          cout << 1 << "\n";
        }
      }
    }
  }
  return 0;
}
