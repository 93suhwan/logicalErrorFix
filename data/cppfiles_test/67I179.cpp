#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, i, a, b, c, sum;
  cin >> t;
  int d[t];
  for (i = 0; i < t; i++) {
    cin >> a >> b >> c;
    sum = (a - b) * 2;
    if (sum < 0) {
      sum = -sum;
    }
    if (sum < 4 && max(a, max(b, c)) > sum) {
      d[i] = -1;
    } else {
      if (c <= sum / 2) {
        d[i] = c + sum / 2;
      } else {
        d[i] = c + sum / 2 - sum;
      }
    }
  }
  for (i = 0; i < t; i++) {
    cout << d[i];
  }
  return 0;
}
