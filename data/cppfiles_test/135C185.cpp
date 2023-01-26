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
    long long sum = 0;
    long long i = n - 1;
    long long j = n - k - 1;
    while (k > 0) {
      sum = sum + a[j] / a[i];
      a[j] = 0;
      a[i] = 0;
      i--;
      j--;
      k--;
    }
    for (long long i = 0; i < n; i++) sum = sum + a[i];
    cout << sum << "\n";
  }
  return 0;
}
