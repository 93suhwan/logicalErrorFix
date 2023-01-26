#include <bits/stdc++.h>
using namespace std;
const int M = 1000000000 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int f = 1;
    for (int i = 1; i <= 2 * n; i++) {
      f = (f * i) % M;
    }
    cout << f / 2 << endl;
  }
}
