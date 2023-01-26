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
    sort(a.begin(), a.end());
    if (n == 2) {
      cout << (a[0] / a[1]) << "\n";
      continue;
    }
    if (n == 3) {
      long long sum1 = a[0] / a[2];
      sum1 = sum1 + a[1];
      long long sum2 = a[0] / a[1];
      sum2 = sum2 + a[2];
      long long sum3 = a[1] / a[2];
      sum3 = sum3 + a[0];
      long long sum = min(sum1, min(sum2, sum3));
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
    long long sum4 = 0;
    k = copyk;
    a = copy;
    i = n / 2;
    long long last = n - 1;
    while (k > 0) {
      if (a[i] != 0 && a[last] != 0) sum4 = sum4 + a[i] / a[last];
      a[i] = 0;
      a[last] = 0;
      i--;
      last--;
      k--;
    }
    for (i = 0; i < n; i++) sum4 = sum4 + a[i];
    long long sum5 = 0;
    k = copyk;
    a = copy;
    i = 1;
    while (k > 0) {
      if (a[i] != 0 && a[i - 1] != 0) sum5 = sum5 + a[i - 1] / a[i];
      a[i] = 0;
      a[i - 1] = 0;
      i++;
      k--;
    }
    for (i = 0; i < n; i++) sum5 = sum5 + a[i];
    long long ans = min(sum1, min(sum2, min(sum3, min(sum4, sum5))));
    cout << ans << "\n";
  }
  return 0;
}
