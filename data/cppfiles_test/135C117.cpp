#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, ans = 0, sum = 0;
  cin >> n >> k;
  vector<long long> x(n);
  for (auto& i : x) {
    cin >> i;
    sum += i;
  }
  sort(begin(x), end(x));
  for (int i = n - k; i < n; i++) {
    sum -= (x[i] + x[i - k]);
    sum += x[i - k] / x[i];
  }
  cout << sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
