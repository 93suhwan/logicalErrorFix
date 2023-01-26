#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, t;
  cin >> t;
  while (t--) {
    cin >> a;
    long long int total = 1;
    for (int i = 3; i <= 2 * a; ++i) {
      total *= i % 1000000007;
    }
    cout << total % 1000000007 + total / 1000000007 << endl;
  }
}
