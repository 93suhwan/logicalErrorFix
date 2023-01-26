#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    long long n;
    cin >> n;
    long long s = sqrt(n);
    long long c = cbrt(n);
    long long p = sqrt(cbrt(n));
    cout << s + c - p << "\n";
  }
}
