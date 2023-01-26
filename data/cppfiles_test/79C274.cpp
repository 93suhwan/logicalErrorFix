#include <bits/stdc++.h>
using namespace std;
void solve(vector<long long>& a) {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long h = 0;
  for (long long i = 0; i < n; i++) {
    h = s[i] - '0';
    if (a[h] == 0) {
      cout << "1\n" << h << "\n";
      return;
    }
  }
  for (long long i = 0; i < 10; i++) h++;
  for (long long i = 0; i < n - 1; i++) {
    h = s[i] - '0';
    for (long long j = i + 1; j < n; j++) {
      long long y = h * 10 + (s[j] - '0');
      if (a[y] == 0) {
        cout << "2\n" << y << "\n";
        return;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<long long> a(101, 1);
  a[1] = 0;
  for (long long i = 2; i <= 100; i++) {
    if (a[i] == 1) {
      for (long long j = 2 * i; j <= 100; j += i) a[j] = 0;
    }
  }
  long long t;
  cin >> t;
  while (t--) {
    solve(a);
  }
  return 0;
}
