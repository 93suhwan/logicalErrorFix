#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int T;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    long long int sq = floor(sqrt(n)), cb = floor(cbrt(n)),
                  both = floor(sqrt(cbrt(n)));
    cout << sq + cb - both << "\n";
  }
  return 0;
}
