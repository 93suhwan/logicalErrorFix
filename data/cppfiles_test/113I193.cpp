#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x1, x2, p1, p2;
    cin >> x1 >> p1;
    cin >> x2 >> p2;
    long long int n1 = x1 * (pow(10, p1));
    long long int n2 = x2 * (pow(10, p2));
    if (n1 < n2)
      cout << "<" << endl;
    else if (n1 > n2)
      cout << ">" << endl;
    else if (n1 == n2)
      cout << "=" << endl;
  }
}
