#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __p(T a) {
  cout << a;
}
template <typename T, typename U>
void __p(pair<T, U> a) {
  cout << "{";
  __p(a.first);
  cout << ",";
  __p(a.second);
  cout << "}";
}
template <typename T>
void __p(std::vector<T> a) {
  cout << "{";
  for (auto it = a.begin(); it < a.end(); it++)
    __p(*it), cout << ",}"[it + 1 == a.end()];
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 2) {
    cout << 2 - k * (a[0] | a[1]) << endl;
    return;
  }
  long long ans = 2 - k * (a[0] | a[1]);
  for (int i = n - 2; i > n - 300 && i >= 0; i--) {
    for (int j = n - 1; j > i; j--) {
      ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
