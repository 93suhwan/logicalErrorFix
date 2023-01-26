#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long OP[200005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long S = 0;
    long long R = 0;
    long long Q = 1;
    for (int j = 1; j <= (n - 1) / 2; j++) {
      Q *= (n - j + 1);
      Q /= (2 * j - 1);
      Q *= (n - j);
      Q /= 2 * j;
      R += Q;
      R %= M;
    }
    OP[0] = 1;
    for (int i = 1; i <= k; i++) {
      OP[i] = OP[i - 1] * R;
      OP[i] %= M;
    }
    long long W = 1;
    long long dwa = 1;
    for (int i = 0; i <= k; i++) {
      if (i == 0) {
        if (k != 0)
          S = OP[k];
        else
          S = 1;
      } else {
        if (i != k) {
          W *= (k - i);
          W /= i;
          dwa *= 2;
          long long vi = dwa;
          vi *= W;
          vi %= M;
          vi *= OP[k - i];
          vi % M;
          S += vi;
          S %= M;
        } else {
          dwa *= 2;
          S += dwa;
        }
      }
    }
    cout << S << "\n";
  }
  return 0;
}
