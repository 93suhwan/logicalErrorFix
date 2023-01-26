#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
void solve() {
  long n;
  cin >> n;
  long long ans = 0;
  long x = 1;
  long a = 0;
  long i = 1;
  while (x <= n) {
    a++;
    i++;
    x = i * i;
  }
  i = 1;
  ans += a;
  a = 0;
  x = 1;
  while (x <= n) {
    a++;
    i++;
    x = i * i * i;
  }
  ans += a;
  a = 0;
  x = 1;
  i = 1;
  while (x <= n) {
    a++;
    i++;
    x = i * i * i * i * i * i;
  }
  ans -= a;
  cout << ans;
}
