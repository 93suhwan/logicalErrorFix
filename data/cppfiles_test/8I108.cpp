#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << n / 3 << ' ' << (int)ceil(n / 3.0) << endl;
  }
  return 0;
}
