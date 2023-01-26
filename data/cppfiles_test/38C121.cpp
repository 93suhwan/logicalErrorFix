#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  unsigned long long n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n & 1) n++;
    if (n <= 6) {
      cout << 15 << endl;
    } else {
      cout << n / 2ULL * 5ULL << endl;
    }
  }
}
