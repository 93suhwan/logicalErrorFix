#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  long long k = 1;
  bool zero = true;
  bool one = true;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0') {
      zero = false;
      break;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1') {
      one = false;
      break;
    }
  }
  if (zero || one) {
    for (long long i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
    return;
  }
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      a[i] = k++;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1') {
      a[i] = k++;
    }
  }
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
