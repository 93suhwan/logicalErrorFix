#include <bits/stdc++.h>
using namespace std;
char S[55];
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> S;
    long long res = 0, maxn = S[0] - 'a' + 1;
    for (int i = 0; i < n; i++) {
      if (S[i] - 'a' + 1 < maxn)
        res++;
      else {
        maxn = max(maxn, (long long)(S[i] - 'a' + 1));
      }
    }
    if (res)
      cout << res + 1 << endl;
    else
      cout << res << endl;
  }
}
