#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int an[N];
int main() {
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    memset(an, 0, sizeof an);
    for (int i = 1; i <= m; i++) {
      cin >> an[i];
    }
    int ii = 0;
    int num = 0, res = 0;
    for (int i = 1; i <= m; i++) {
      if (an[i] > i && an[i] > res) {
        num = i;
        res = an[i];
      }
    }
    int ans;
    ans = res - num;
    cout << ans << endl;
  }
}
