#include <bits/stdc++.h>
#pragma GCC optimise("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")
using namespace std;
void run_case() {
  long long k;
  cin >> k;
  long long root_less = sqrt(k);
  long long root_more = sqrt(k) + 1;
  if (root_less * root_less == k) {
    cout << root_less << ' ' << 1 << '\n';
    return;
  }
  if (k < root_less * root_less + root_more) {
    cout << k - root_less * root_less << ' ' << root_more << '\n';
    return;
  }
  cout << root_more << ' ' << root_more * root_more - k + 1 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long test_case = 1;
  cin >> test_case;
  while (test_case--) {
    run_case();
  }
  return 0;
}
