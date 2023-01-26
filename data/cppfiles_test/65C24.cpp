#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
const double EPS = 1e-9;
const long long INF = 1e18;
const long long N = 1e6 + 5;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long &x : a) cin >> x;
  sort(a.begin(), a.end());
  string s;
  cin >> s;
  long long c = 0;
  for (long long i = 0; i + 1 < n; i++) c += s[i + 1] != s[i];
  long long l = n - c - 1, r = n - c - 1;
  char L = s[0];
  cout << a[l] << " " << s[0] << "\n";
  for (long long i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      r++;
      cout << a[r] << " " << s[i] << "\n";
    } else {
      l--;
      L = L == 'R' ? 'L' : 'R';
      cout << a[l] << " " << L << "\n";
    }
  }
  return 0;
}
