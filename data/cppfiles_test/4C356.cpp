#include <bits/stdc++.h>
using namespace std;
bool ISPRIME(long long n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    if (!(x & 1)) {
      cout << 2 << " " << x << endl;
    } else {
      cout << 2 << " " << x - 1 << endl;
    }
  }
}
