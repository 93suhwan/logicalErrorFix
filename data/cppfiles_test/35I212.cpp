#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    if (M < N)
      cout << 0 << endl;
    else if (M == N)
      cout << 1 << endl;
    else {
      int r = N, s = M + 1;
      int cnt = 0;
      while (r) {
        r >>= 1;
        s >>= 1;
        cnt++;
      }
      s <<= cnt;
      if (N > M - s)
        cout << s << endl;
      else {
        cout << ((M + 1) ^ N) << endl;
      }
    }
  }
  return 0;
}
