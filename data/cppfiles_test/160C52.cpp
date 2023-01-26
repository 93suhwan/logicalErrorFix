#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N, M, Rb, Cb, Rd, Cd;
    cin >> N >> M >> Rb >> Cb >> Rd >> Cd;
    int Ans = 0;
    int CntX = 1;
    int CntY = 1;
    while (Rb != Rd && Cb != Cd) {
      if (Rb == N)
        CntX = -1;
      else if (Rb == 1)
        CntX = 1;
      if (Cb == M)
        CntY = -1;
      else if (Cb == 1)
        CntY = 1;
      Rb += CntX;
      Cb += CntY;
      Ans++;
    }
    cout << Ans << "\n";
  }
  return 0;
}
