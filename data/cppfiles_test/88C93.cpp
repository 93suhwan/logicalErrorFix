#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
bool mycomp(T x, T y) {
  return (x == y);
}
bool paircomp(const pair<long long int, long long int> &x,
              const pair<long long int, long long int> &y) {
  return x.second < y.second;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  ;
  if (n % 2 == 0) {
    cout << "YES";
    return;
  }
  for (long long int i = 0; i < n - 1; i++) {
    if (a[i] >= a[i + 1]) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
