#include <bits/stdc++.h>
using namespace std;
void solve() {}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = n / 3;
    int rem = n - 3 * x;
    if (rem == 0) {
      cout << x << " " << x << "\n";
    } else if (rem == 1) {
      cout << x + 1 << " " << x << "\n";
    } else {
      cout << x << " " << x + 1 << "\n";
    }
  }
  return 0;
}
