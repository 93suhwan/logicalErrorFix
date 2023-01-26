#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    long int a, b, c;
    cin >> a >> b >> c;
    long int sum = a + 2 * b + 3 * c;
    cout << sum % 2 << endl;
  }
  return 0;
}
