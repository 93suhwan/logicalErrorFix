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
    double temp1 = log10((double)x1) + (double)p1;
    double temp2 = log10((double)x2) + (double)p2;
    if (temp1 < temp2) {
      cout << '<' << '\n';
    } else if (temp1 > temp2) {
      cout << '>' << '\n';
    } else {
      cout << '=' << '\n';
    }
  }
}
