#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int l, r;
    l = -(n - 1);
    r = n;
    std::cout << l << " " << r << endl;
  }
  return 0;
}
