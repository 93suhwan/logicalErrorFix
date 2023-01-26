#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x = n / 10;
    x += n % 10 == 9 ? 1 : 0;
    cout << x << endl;
  }
  return 0;
}
