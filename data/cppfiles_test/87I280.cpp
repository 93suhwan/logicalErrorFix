#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
void solve() {
  long long n;
  cin >> n;
  long long maxi = INT_MIN;
  long long pos = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    maxi = max((x - i), maxi);
  }
  cout << maxi;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
    cout << endl;
  }
  return 0;
}
