#include <bits/stdc++.h>
using namespace std;
int abs(int a) { return a > 0 ? a : -a; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int sq = 1;
    long long int cnt = 1;
    long long int k;
    cin >> k;
    while (k > sq) {
      cnt++;
      sq = cnt * cnt;
    }
    int r = cnt;
    int c = 0;
    int leftOver = 0;
    int cdispAllowed = cnt - 1;
    if (cdispAllowed >= sq - k) {
      c = sq - k + 1;
    } else {
      c = cnt;
      leftOver = (sq - k) - cdispAllowed;
    }
    r -= leftOver;
    cout << r << " " << c << endl;
  }
  return 0;
}
