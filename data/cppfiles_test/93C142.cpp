#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long a, b;
    cin >> a >> b;
    vector<long long> res = {a - 1, 1, a, 0};
    long long p = res[(a - 1) % 4] ^ b;
    if (p == 0) {
      cout << a;
    } else if (p < a) {
      cout << a + 1;
    } else if (p == a) {
      cout << a + 2;
    } else {
      cout << a + 1;
    }
    cout << "\n";
  }
}
