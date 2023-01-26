#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2) cout << 'a';
    for (long long i = 1; i < n / 2; ++i) {
      cout << 'b';
    }
    cout << 'c';
    for (long long i = n / 2; i < n - 1; ++i) {
      cout << 'b';
    }
    cout << endl;
  }
}
