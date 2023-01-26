#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long sz(long long T, long long pot) {
  if (pot == 1) {
    return T;
  }
  if (pot % 2 == 1)
    return ((sz((T * T) % M, pot / 2) * T) + M) % M;
  else
    return (sz((T * T) % M, pot / 2) + M) % M;
}
long long OP[200005];
long long IV[200005];
int main() {
  for (int i = 1; i < 200005; i++) {
    IV[i] = sz(i, M - 2);
  }
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long S = 0;
    long long R = 0;
    long long Q = 1;
    for (int j = 1; j <= (n - 1) / 2; j++) {
      Q *= (n - 2 * j + 2);
      Q = (Q + M) % M;
      Q *= IV[2 * j - 1];
      Q = (Q + M) % M;
      Q *= (n - 2 * j + 1);
      Q = (Q + M) % M;
      Q *= IV[2 * j];
      Q = (Q + M) % M;
      R += Q;
      R = (R + M) % M;
    }
    OP[0] = 1;
    for (int i = 1; i <= k; i++) {
      OP[i] = OP[i - 1] * R;
      OP[i] = (OP[i] + M) % M;
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
          W *= (k - i + 1);
          W = (W + M) % M;
          W *= IV[i];
          W = (W + M) % M;
          dwa *= 2;
          dwa = (dwa + M) % M;
          long long vi = dwa;
          vi *= W;
          vi = (vi + M) % M;
          vi *= OP[k - i];
          vi = (vi + M) % M;
          S += vi;
          S = (S + M) % M;
        } else {
          dwa *= 2;
          dwa = (dwa + M) % M;
          S += dwa;
        }
        S = (S + M) % M;
      }
    }
    cout << S << "\n";
  }
  return 0;
}
