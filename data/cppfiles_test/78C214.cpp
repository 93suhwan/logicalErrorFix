#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long mid = r / 2 + 1;
    mid >= l ? cout << r % mid << endl : cout << r % l << endl;
  }
  return 0;
}
