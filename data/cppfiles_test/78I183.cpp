#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n, l = 0;
  cin >> x >> n;
  l = 31 - __builtin_clz(n);
  l++;
  cout << (1 << l) - 1;
  return 0;
}
