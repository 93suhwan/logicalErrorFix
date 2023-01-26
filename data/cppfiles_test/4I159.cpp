#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 5)
      cout << 2 << " " << 3 << endl;
    else
      cout << 2 << " " << n / 2 << endl;
  }
  return 0;
}
