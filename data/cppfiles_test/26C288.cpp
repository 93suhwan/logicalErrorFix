#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, z;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    long long p = 1;
    n = n * 2;
    z = n * 2;
    if (z == 2) p = 1;
    while (1 && n != 2) {
      p = (p * n) % 1000000007;
      n--;
    }
    cout << p << endl;
  }
  return 0;
}
