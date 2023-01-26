#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x, n;
  int i = 1;
  cin >> x >> n;
  while (n != 0) {
    if (x % 2 == 0) {
      x = x - i;
    } else {
      x = x + i;
    }
    i++;
    n--;
  }
  cout << x << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    solve();
    t--;
  }
}
