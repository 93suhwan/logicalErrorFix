#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    string x;
    cin >> x;
    long long a = 0, b = 0;
    for (int i = 0; i < x.size(); i++) {
      if (i & 1)
        a = a * 10 + x[i] - '0';
      else
        b = b * 10 + x[i] - '0';
    }
    std::cout << (a + 1) * (b + 1) - 2 << "\n";
  }
  return 0;
}
