#include <bits/stdc++.h>
using namespace std;
void main0() {
  long long x, n;
  cin >> x >> n;
  long long res;
  if (n % 4 == 0) {
    res = x;
  } else if (n % 4 == 1) {
    res = (x % 2 == 0) ? x - n : x + n;
  } else if (n % 4 == 2) {
    res = (x % 2 == 0) ? x + 1 : x - 1;
  } else {
    res = (x % 2 == 0) ? x + n + 1 : x - n - 1;
  }
  cout << res << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) main0();
  return 0;
}
