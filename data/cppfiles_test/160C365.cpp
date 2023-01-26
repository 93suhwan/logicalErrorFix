#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m, roww, coll, rowww, colll;
    cin >> n >> m >> roww;
    cin >> coll >> rowww >> colll;
    int flag = 0;
    int cnt = 0;
    int stpa = 1, stpb = 1;
    while (flag == 0) {
      if (roww == rowww || coll == colll) {
        flag = 1;
        break;
      } else {
        if (roww + stpa > n || roww + stpa < 1) stpa *= -1;
        if (coll + stpb > m || coll + stpb < 1) stpb *= -1;
      }
      roww += stpa;
      coll += stpb;
      cnt++;
    }
    cout << cnt << "\n";
  }
  return 0;
}
