#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const long long mod = 1000000007;
void solv() {
  long long n, d;
  cin >> n >> d;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % d == 0) {
    long long ans = -1;
    for (long long i = 0; i < d; i++) {
      long long fr = -1, g = 0, mg = -1;
      for (long long j = 0; i + j < n; j += d) {
        if (fr == -1 && a[i + j] == 0) fr = j / d;
        if (a[i + j] == 1)
          g++;
        else {
          mg = max(g, mg);
          g = 0;
        }
      }
      if (fr != -1)
        mg = max(mg, g + fr);
      else {
        cout << -1 << "\n";
        return;
      }
      ans = max(ans, mg);
    }
    cout << ans << "\n";
    return;
  }
  vector<bool> v(n);
  long long i = 0;
  long long fr = -1, t = 0, ans = -1;
  long long c = 0;
  while (1) {
    if (v[i]) break;
    v[i] = true;
    if (fr == -1 && a[i] == 0) fr = c;
    if (a[i] == 1)
      t++;
    else {
      ans = max(t, ans);
      t = 0;
    }
    c++;
    i += d;
    i %= n;
  }
  if (fr != -1)
    ans = max(ans, t + fr);
  else {
    cout << -1 << "\n";
    return;
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test_cases = 1;
  cin >> test_cases;
  for (long long curr_case = 1; curr_case <= test_cases; curr_case++) {
    solv();
  }
  return 0;
}
