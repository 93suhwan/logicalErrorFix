#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
  if (n % (n + 1) == n % (n + 3)) {
    cout << n + 1 << " " << n + 3 << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }
}
