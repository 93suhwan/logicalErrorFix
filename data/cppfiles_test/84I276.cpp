#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
void solve() {
  long long n, s;
  cin >> n >> s;
  if (n == 1) {
    cout << s << "\n";
  } else if (n == s) {
    cout << 1 << "\n";
  } else if (n > s) {
    long long zeroes = n - s;
    long long mid = ceil(n / 2);
    if (zeroes >= mid)
      cout << 0 << "\n";
    else
      cout << 1 << "\n";
  } else {
    int mid = n / 2;
    if (mid * 2 < n) mid++;
    int index = n - mid + 1;
    int val = ceil(s / index);
    while (val) {
      if ((val * index) <= s) {
        cout << val << "\n";
        return;
      }
      val--;
    }
    cout << 0 << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
