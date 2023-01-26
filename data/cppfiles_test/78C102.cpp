#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long min_cnt = LLONG_MAX;
  vector<long long> arr(33, 0);
  long long temp, k;
  long long z_cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (!temp) z_cnt++;
    k = 0;
    while (temp) {
      arr[k] += temp & 1;
      temp >>= 1;
      k++;
    }
  }
  if (z_cnt == n) {
    for (int i = 1; i < n + 1; i++) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = 0; i < 32; i++) {
    if (arr[i]) min_cnt = min(min_cnt, arr[i]);
  }
  bool ok = true;
  for (int i = 1; i < min_cnt + 1; i++) {
    ok = true;
    for (int j = 0; j < 32; j++) {
      if (arr[j] > 0) {
        if (arr[j] % i != 0) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      cout << i << " ";
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
