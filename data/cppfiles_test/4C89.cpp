#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, a, b;
  cin >> n;
  if (n == 5) {
    cout << 2 << " " << 4 << endl;
    return;
  }
  n--;
  cout << 2 << " " << n / 2 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }
  return 0;
}
