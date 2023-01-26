#include <bits/stdc++.h>
using namespace std;
struct noode {
  int l, r, d;
} b[100];
int a[100];
int c[100];
int main(int argc, const char* argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int k = 0;
    for (int i = 0; i < n - 1; ++i) {
      bool flag = false;
      for (int j = 0; j < n - 1; ++j) {
        if (a[j] > a[j + 1]) {
          flag = true;
        }
      }
      if (!flag) break;
      int r = 0;
      for (int j = 0; j < n - i; ++j) {
        if (a[r] < a[j]) {
          r = j;
        }
      }
      if (r != n - i - 1) {
        b[k].l = 1;
        b[k].r = n - i;
        b[k++].d = r + 1;
      }
      for (int j = 0; j <= r; ++j) c[j] = a[j];
      for (int j = r + 1; j < n - i; ++j) a[j - (r + 1)] = a[j];
      for (int j = n - i - r - 1; j < n - i; ++j) a[j] = c[j - (n - i - r - 1)];
    }
    cout << k << endl;
    for (int i = 0; i < k; ++i)
      cout << b[i].l << " " << b[i].r << " " << b[i].d << endl;
    for (int i = 0; i < n; ++i) a[i] = 0;
  }
  return 0;
}
