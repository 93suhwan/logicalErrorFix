#include <bits/stdc++.h>
using namespace std;
void solve(long long x, long long n) {
  long long y = n / 4 * 4;
  y++;
  while (y <= n) {
    if (x % 2 == 0) {
      x -= y;
    } else {
      x += y;
    }
    y++;
  }
  cout << x << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    solve(x, n);
  }
}
