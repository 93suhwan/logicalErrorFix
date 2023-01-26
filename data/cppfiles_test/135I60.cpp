#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    if (k == 0) {
      long long sum = 0;
      for (long long i = 0; i < n; i++) sum = sum + a[i];
      cout << sum << "\n";
      continue;
    }
    sort(a.begin(), a.end());
    if (n == 2) {
      cout << (a[0] / a[1]) << "\n";
      continue;
    }
    if (n == 3) {
      long long sum = a[0] / a[2];
      sum = sum + a[1];
      cout << sum << "\n";
      continue;
    }
    long long sum1 = 0, sum2 = 0, sum3 = 0;
    long long mid = n / 2;
    mid = mid + 1;
    vector<long long> copy(n);
    copy = a;
    long long copyk = k;
    long long i = 0;
    while (k > 0) {
      if (a[i] != 0 && a[mid] != 0) sum1 = sum1 + a[i] / a[mid];
      a[i] = 0;
      a[mid] = 0;
      i++;
      mid++;
      k--;
    }
    for (i = 0; i < n; i++) sum1 = sum1 + a[i];
    k = copyk;
    a = copy;
    i = n - 1;
    while (k > 0) {
      if (a[i] != 0 && a[i - 1] != 0) sum2 = sum2 + a[i - 1] / a[i];
      a[i] = 0;
      a[i - 1] = 0;
      i = i - 2;
      k--;
    }
    for (i = 0; i < n; i++) sum2 = sum2 + a[i];
    k = copyk;
    a = copy;
    i = 0;
    while (k > 0) {
      if (a[i] != 0 && a[n - i - 1] != 0) sum3 = sum3 + a[i] / a[n - i - 1];
      a[i] = 0;
      a[n - i - 1] = 0;
      i++;
      k--;
    }
    for (i = 0; i < n; i++) sum3 = sum3 + a[i];
    long long ans = min(sum1, min(sum2, sum3));
    cout << ans << "\n";
  }
  return 0;
}
