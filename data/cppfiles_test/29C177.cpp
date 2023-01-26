#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < (int)(n); i++) cin >> A[i];
    long long c0 = 0, c1 = 0;
    for (int i = 0; i < (int)(n); i++) {
      if (A[i] == 0)
        c0++;
      else if (A[i] == 1)
        c1++;
    }
    long long t = 1;
    for (int i = 0; i < (int)(c0); i++) t *= 2;
    cout << c1 * t << endl;
  }
  return 0;
}
