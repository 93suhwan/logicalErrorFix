#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
struct interval {
  long long sp, b;
};
bool compareInterval(interval i1, interval i2) {
  if (i1.sp == i2.sp) return (i1.b < i2.b);
  return (i1.sp < i2.sp);
}
void solve() {
  long long i, j, n;
  cin >> n;
  string s;
  cin >> s;
  char max = s[0];
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  long long count = 0;
  for (long long i = 1; i < n; i++) {
    if (s[i] < max) {
      count++;
    }
    if (s[i] > max) max = s[i];
  }
  if (count == 0)
    cout << count << endl;
  else
    cout << count + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
