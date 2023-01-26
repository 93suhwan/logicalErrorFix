#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string badi;
    string choti;
    cin >> badi >> choti;
    int choti_s = choti.size();
    int badi_s = badi.size();
    int prev = 0, ans = 0;
    for (int i = 0; i < choti_s; i++) {
      for (int j = 0; j < badi_s; j++) {
        if (choti[i] == badi[j]) {
          if (i == 0) {
            prev = j;
          } else {
            ans = ans + abs(j - prev);
            prev = j;
          }
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
