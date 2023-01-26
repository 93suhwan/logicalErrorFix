#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 1e9 + 7;
double eps = 1e-12;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  double k = (double)sum / n;
  bool f = true;
  for (long long i = 0; i < n; i++) {
    if (arr[i] != k) {
      f = false;
      break;
    }
  }
  if (f) {
    cout << n * (n - 1) / 2 << '\n';
    return;
  }
  sort(arr, arr + n);
  long long ans = 0;
  k *= 2;
  long long i = 0, j = n - 1;
  while (i < j) {
    long long x = arr[i] + arr[j];
    if (x == k) {
      ans++;
      i++;
      j--;
    } else if (x > k) {
      j--;
    } else
      i++;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
