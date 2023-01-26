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
  unordered_map<long long, long long> make_pair;
  for (long long i = 0; i < n; i++) {
    make_pair[arr[i]]++;
  }
  long long ans = 0;
  for (auto i : make_pair) {
    long long x = i.first;
    long long y = i.second;
    if (y > 1) {
      if (abs(x - k) < 1e-10) {
        ans += (y) * (y - 1) / 2;
      }
    }
  }
  k *= 2;
  long long i = 0, j = n - 1;
  while (i < j) {
    long long x = arr[i] + arr[j];
    if (abs(x - k) < 1e-10) {
      if (arr[i] != arr[j]) ans++;
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
