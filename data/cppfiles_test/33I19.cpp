#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
long long myceil(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
bool isPerSquare(long double a) {
  if (a < 0) return false;
  long long sr = sqrt(a);
  return (sr * sr == a);
}
long long arr1[200002];
long long arr2[200002];
long long arr2D[1001][1001];
vector<long long> vec;
void solve() {
  long long n, m, a, b, c, d;
  string s;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> arr1[i];
  long long ind = max_element(arr1, arr1 + n) - arr1;
  set<long long> vals;
  long long mymax = arr1[ind];
  long long ans = -2e18;
  for (long long j = ind + 1; j < n; j++) {
    vals.insert(arr1[j]);
    ans = max(ans, mymax * (*vals.begin()));
  }
  vals.clear();
  for (long long j = ind - 1; j >= 0; j--) {
    vals.insert(arr1[j]);
    ans = max(ans, mymax * (*vals.begin()));
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
