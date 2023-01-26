#include <bits/stdc++.h>
using namespace std;
long long n;
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
  vector<long long> ans;
  long long hs = n * (n + 1) / 2;
  if (sum % hs != 0) {
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
    if (x < 0) {
      cout << "NO" << '\n';
      return;
    }
    if (x % n != 0) {
      cout << "NO" << '\n';
      return;
    }
    x = x / n;
    ans.push_back(x);
  }
  long long curSum = 0;
  for (auto i : ans) curSum += i;
  if (curSum != total) {
    cout << "NO" << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    int dem = 0;
    curSum = 0;
    for (int j = i; j >= 1; j--) {
      curSum += j * ans[dem];
      dem++;
    }
    for (int j = n; j > i; j--) {
      curSum += j * ans[dem];
      dem++;
    }
    if (curSum != a[i]) {
      cout << "NO" << '\n';
      return;
    }
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
