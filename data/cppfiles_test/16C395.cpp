#include <bits/stdc++.h>
using namespace std;
char S[55];
char S2[55];
long long dp[55];
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> S;
    strcpy(S2, S);
    sort(S2, S2 + n);
    long long res = 0, maxn = 0;
    for (int i = 0; i < n; i++) {
      if (S[i] != S2[i]) res++;
    }
    cout << res << endl;
  }
}
