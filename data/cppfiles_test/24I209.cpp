#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n < 10)
      cout << 1;
    else
      cout << (n / 10);
  }
  return 0;
}
