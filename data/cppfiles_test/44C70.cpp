#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int c, d;
    cin >> c >> d;
    if (c == 0 and d == 0)
      std::cout << "0" << std::endl;
    else if (c == d)
      std::cout << "1" << std::endl;
    else if ((c + d) % 2 == 0)
      std::cout << "2" << std::endl;
    else
      std::cout << "-1" << std::endl;
  }
  return 0;
}
