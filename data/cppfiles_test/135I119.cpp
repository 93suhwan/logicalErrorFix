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
  for (int i = 0; i < k; i++) {
    sum -= (x[i] + x[n - k + i]);
    sum += x[i] / x[n - k + i];
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
