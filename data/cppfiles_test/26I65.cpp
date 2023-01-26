#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    long long p = 1;
    long long z = 2 * n;
    while (z >= 2) {
      p *= z % 1000000007;
      z--;
    }
    cout << (p) << endl;
  }
  return 0;
}
