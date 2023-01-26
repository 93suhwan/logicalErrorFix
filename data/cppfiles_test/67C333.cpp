#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b, c, result, f;
  cin >> a >> b >> c;
  result = abs(a - b);
  if (a > result * 2 || b > result * 2 || c > result * 2) {
    cout << "-1" << endl;
  } else if (c + result > result * 2) {
    cout << (c + result) - (result * 2) << endl;
  } else {
    cout << result + c << endl;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
