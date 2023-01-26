#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long N = 2e7 + 10;
const long double PI = acos(-1);
using namespace std;
void judge() {
  long long n;
  cin >> n;
  long long a[n];
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> s;
  sort(a, a + n);
  long long l = 0, r = n - 1;
  long long i = 0;
  while (l <= r) {
    if (s[i] == '1') {
      cout << a[r] << ' ';
      r--;
    } else {
      cout << a[l] << ' ';
      l++;
    }
    i++;
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    judge();
  }
  return 0;
}
