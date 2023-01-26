#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << (int)ceil(n / 3.0) << ' ' << n / 3 << endl;
  }
  return 0;
}
