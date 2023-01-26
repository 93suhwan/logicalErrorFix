#include <bits/stdc++.h>
using namespace std;
int a[10];
long long v[10];
long long pw[12];
int len(long long x) {
  int ans = 0;
  while (x) {
    ans++;
    x /= 10;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  pw[0] = 1;
  for (int i = 1; i <= 10; i++) pw[i] = pw[i - 1] * 10;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    k++;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
      v[i] = min(k, pw[a[i] - a[i - 1]] - 1);
      k -= v[i];
    }
    bool flag = false;
    if (k != 0) {
      cout << k;
      flag = true;
    }
    for (int i = n - 2; i >= 0; i--) {
      if (flag)
        for (int j = 1; j <= a[i + 1] - a[i] - len(v[i + 1]); j++) cout << "0";
      if (v[i + 1] != 0) {
        cout << v[i + 1];
        flag = true;
      }
    }
    cout << "\n";
  }
}
