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
