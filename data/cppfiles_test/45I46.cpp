#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n, out = 1, prev = -1;
    cin >> n;
    for (long long j = 0; j < n; j++) {
      long long x;
      cin >> x;
      if (x) {
        out++;
        if (prev == 1) {
          out += 4;
        }
        prev = 1;
      } else {
        if (prev == 0) {
          out = -1;
          break;
        }
        prev = 0;
      }
    }
    cout << out << "\n";
  }
  return 0;
}
