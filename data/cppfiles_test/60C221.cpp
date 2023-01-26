#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 1e9 + 7;
double eps = 1e-12;
struct idx {
  long long s, e;
};
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
  sort(arr, arr + n);
  map<long long, idx> make_pair;
  for (long long i = 0; i < n;) {
    idx q;
    q.s = i;
    for (long long j = i + 1; j < n; j++) {
      if (arr[j] == arr[i]) {
        i++;
      } else
        break;
    }
    q.e = i;
    make_pair[arr[i]] = q;
    i++;
  }
  long long ans = 0;
  k *= 2;
  long long i = 0, j = n - 1;
  while (i < j) {
    long long x = arr[i] + arr[j];
    if (x == k) {
      long long st = make_pair[arr[j]].s;
      long long ed = make_pair[arr[j]].e;
      ans += j - max(i + 1, st) + 1;
      st = make_pair[arr[i]].s;
      ed = make_pair[arr[i]].e;
      ans += min(ed, j - 1) - i;
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
