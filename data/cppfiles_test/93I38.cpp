#include <bits/stdc++.h>
using namespace std;
void solve() {
  long n, k;
  cin >> n >> k;
  long x = 1;
  long num = 1;
  long h = 0;
  while (num < n) {
    num += x;
    if (x < k) {
      x++;
    }
    h++;
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
