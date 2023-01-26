#include <bits/stdc++.h>
using namespace std;
bool is_valid(long long a[], long long n, long long h, long long k) {
  long long num = 0;
  for (int i = 0; i < n - 1; i++) {
    num += min(k, a[i + 1] - a[i]);
  }
  num += k;
  if (num >= h) return 1;
  return 0;
}
long long binary_Search(long long a[], long long n, long long h, long long l,
                        long long r) {
  if (n == 1) return h;
  if (abs(l - r) <= 1) {
    if (is_valid(a, n, h, l)) return l;
    return r;
  }
  if (is_valid(a, n, h, (l + r) / 2)) {
    return binary_Search(a, n, h, l, (l + r) / 2);
  }
  return binary_Search(a, n, h, (l + r) / 2 + 1, r);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << binary_Search(a, n, h, 0, h) << endl;
    ;
  }
}
