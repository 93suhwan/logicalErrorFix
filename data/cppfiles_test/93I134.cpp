#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  int x = 1;
  int num = 1;
  int h = 0;
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
