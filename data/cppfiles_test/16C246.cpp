#include <bits/stdc++.h>
using namespace std;
void run_case() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> a(n);
  for (long long i = 0; i < n; i++) {
    a[i] = s[i];
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] != s[i]) ans++;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    run_case();
  }
}
