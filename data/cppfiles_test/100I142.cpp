#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimization("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
bool tc = 1;
void run_case() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  long long int ans = v[0];
  sort(v.rbegin(), v.rend());
  while (v.size() > 1) {
    if (v[v.size() - 1] > (v[v.size() - 2] - v[v.size() - 1])) {
      ans = v[v.size() - 1];
      break;
    }
    long long int mn = v.back();
    v.pop_back();
    for (long long int i = 0; i < v.size(); i++) v[i] -= mn;
  }
  if (v.size() == 1) ans = v[0];
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (tc) {
    int t;
    cin >> t;
    while (t--) run_case();
  } else
    run_case();
  return 0;
}
