#include <bits/stdc++.h>
using namespace std;
int Test;
string x, y;
int T[210];
int A[1010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> Test;
  for (int i = 1; i <= Test; i++) {
    cin >> x >> y;
    bool Ans = 1;
    int id = x.size() - 1, last = x.size();
    for (int j = y.size() - 1; j >= 0; j--) {
      bool tf = 0;
      while (id >= 0) {
        if (x[id] != y[j])
          id--;
        else {
          if ((last - id) % 2) {
            tf = 1;
            last = id;
            break;
          } else {
            id--;
          }
        }
      }
      if (!tf) {
        Ans = 0;
        break;
      }
    }
    if (Ans)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
