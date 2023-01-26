#include <bits/stdc++.h>
using namespace std;
const uint32_t MAXN = 2e5 + 1;
void slove() {
  int64_t n, ans = 0, k, su = 0;
  vector<uint64_t> arr, temp;
  cin >> n;
  for (uint64_t i = 0, x; i < n; i++) {
    cin >> x;
    arr.push_back(x);
    su += x;
  }
  if (n == 1) {
    cout << "YES\n";
    cout << arr[0];
    cout << '\n';
    return;
  }
  if (n % 2 == 0)
    k = (n / 2) * (n + 1);
  else
    k = n * ((n - 1) / 2 + 1);
  if (su % k != 0 || su / k < n) {
    cout << "NO\n";
    return;
  }
  su /= k;
  for (int32_t i = 0; i < n; i++) {
    temp.push_back(arr[i] - su);
  }
  for (int64_t i = 0; i < n; i++) {
    arr[i] = (arr[i] - temp[(i + 1) % n]) / n;
  }
  cout << "YES\n";
  cout << arr[n - 1] << " ";
  for (uint32_t i = 0; i < n - 1; i++) {
    cout << arr[i] << " ";
  }
  cout << '\n';
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  uint32_t t;
  cin >> t;
  while (t--) {
    slove();
  }
}
