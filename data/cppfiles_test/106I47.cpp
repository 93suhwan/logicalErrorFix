#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= 2 * n; i++) {
      if (i % 2 != 0) cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
