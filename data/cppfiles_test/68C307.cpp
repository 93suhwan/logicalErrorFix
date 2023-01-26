#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long int k;
    cin >> k;
    long long int sq = sqrt(k);
    if (sq * sq != k) ++sq;
    long long int a = (sq - 1) * (sq - 1) + 1;
    long long int df = abs(k - a);
    long long int in1, in2;
    if (df < sq) {
      in2 = sq;
      in1 = df + 1;
    } else {
      in1 = sq;
      long long int b = df - sq;
      in2 = sq - b - 1;
    }
    cout << in1 << ' ' << in2 << endl;
  }
  return 0;
}
