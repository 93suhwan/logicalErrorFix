#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, x = 0;
  cin >> a >> b;
  long long c = a;
  if (a == 1) {
    if (b == 1) {
      c += 2;
    } else {
      c++;
    }
    cout << c << "\n";
    return;
  }
  int j = 0, p = 1;
  while (p < a) {
    j++;
    p = pow(2, j);
  }
  j--;
  for (int i = pow(2, j); i < a; i++) {
    x ^= i;
  }
  if (x != b) c++;
  cout << c << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
