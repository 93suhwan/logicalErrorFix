#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long x = 1;
  long long num = 1;
  long long h = 0;
  while (num < n) {
    num += x;
    x = num;
    if (x >= k) {
      x = k;
      h++;
      break;
    }
    h++;
  }
  if (num < n) {
    long long c = n - num;
    if (c % k == 0) {
      h += c / k;
    } else {
      h += c / k + 1;
    }
  }
  cout << h << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
