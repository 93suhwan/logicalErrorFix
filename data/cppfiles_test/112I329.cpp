#include <bits/stdc++.h>
using namespace std;
void Home_work() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, m;
    cin >> a >> b >> c >> m;
    if (m <= 0)
      cout << "yes" << endl;
    else if (a == 1 && b == 1 && c == 1)
      cout << "no" << endl;
    else if (((a / m) + (b / m) + (c / m)) >= m)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}
int main() { Home_work(); }
