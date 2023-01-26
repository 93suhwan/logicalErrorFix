#include <bits/stdc++.h>
using namespace std;
long long t, n, k, gt;
vector<long long> a, mx, pw;
long long ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for (int I = 0; I < t; I++) {
    ans = 0;
    a.clear();
    mx.clear();
    cin >> n >> k;
    k++;
    a.resize(n);
    mx.resize(n);
    pw.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pw[i] = powl(10, a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
      mx[i] = pw[i + 1] / pw[i] - 1;
    }
    for (int i = 0; i < n - 1; i++) {
      gt = min(mx[i], k);
      ans += gt * pw[i];
      k -= gt;
    }
    ans += k * pw[n - 1];
    cout << ans << "\n";
  }
}
