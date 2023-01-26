#include <bits/stdc++.h>
const int MAX = 1e7 + 10;
bool isPrime(long long NN) {
  for (long long i = 2; i * i <= NN; ++i) {
    if (NN % i == 0) return false;
  }
  return true;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string second;
    cin >> second;
    long long x = 0, y = 0, z = 0;
    for (long long i = 0; i < second.length(); i++) {
      if (second[i] == 'A') {
        x++;
      }
      if (second[i] == 'B') {
        y++;
      }
      if (second[i] == 'C') {
        z++;
      }
    }
    if (x + z == y) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}
