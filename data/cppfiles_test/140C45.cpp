#include <bits/stdc++.h>
using namespace std;
double root(int base, int exp) {
  for (int i = 1; i <= base; i++) {
    int ans = 1;
    for (int j = 0; j < exp; j++) {
      ans *= i;
    }
    if (ans > base) return i - 1;
    if (ans == base) return i;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << root(n, 2) + root(n, 3) - root(n, 6) << '\n';
  }
}
