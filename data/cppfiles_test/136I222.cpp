#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long ans[40010];
long long a[400010];
long long sum = 0;
void read() {
  cin >> n;
  sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
}
void solve() {
  vector<int> ans;
  long long hs = n * (n + 1) / 2;
  if (sum % n != 0) {
    cout << "NO" << '\n';
    return;
  }
  long long total = sum / hs;
  if (total < n) {
    cout << "NO" << '\n';
    return;
  }
  a[0] = a[n];
  for (int i = 1; i <= n; i++) {
    long long tmp = a[i] - a[i - 1];
    long long x = total - tmp;
    if (x % n != 0) {
      cout << "NO" << '\n';
      return;
    }
    x = x / n;
    ans.push_back(x);
  }
  cout << "YES" << '\n';
  for (auto i : ans) cout << i << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    read();
    solve();
  }
  return 0;
}
