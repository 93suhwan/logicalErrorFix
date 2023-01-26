#include <bits/stdc++.h>
using namespace std;
void chll_bnao() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  sort((arr).begin(), (arr).end());
  long double k = 0;
  for (long long i = 0; i < n - 1; i++) k += arr[i];
  printf("%.10Lf\n", arr[n - 1] + k / (n - 1));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    chll_bnao();
  }
}
