#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    if (n < 6)
      cout << 15 << endl;
    else
      cout << (++n / 2) * 5 << endl;
  }
}
