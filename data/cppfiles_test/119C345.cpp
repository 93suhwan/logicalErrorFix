#include <bits/stdc++.h>
using namespace std;
int solve(int n) {
  int sum = 0;
  int ax;
  for (int i = 0; i < n; i++) {
    cin >> ax;
    sum += ax;
  }
  if (sum % n == 0)
    return 0;
  else
    return 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << solve(n) << endl;
  }
  return 0;
}
