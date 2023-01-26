#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int x1, p1;
    cin >> x1 >> p1;
    int x2, p2;
    cin >> x2 >> p2;
    double temp1 = log10(x1 / x2) + p1 - p2;
    if (temp1 < 0) {
      cout << '<' << '\n';
    } else if (temp1 > 0) {
      cout << '>' << '\n';
    } else {
      cout << '=' << '\n';
    }
  }
}
