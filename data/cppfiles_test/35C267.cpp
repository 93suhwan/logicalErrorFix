#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int qqq;
  cin >> qqq;
  for (int qq = 0; qq < qqq; ++qq) {
    long long n, m, last_i = 31;
    cin >> n >> m;
    bitset<32> N = n, M = m, ANS;
    for (int i = 31; i >= 0; --i) {
      if (N[i] == 0 && M[i] == 0)
        last_i = i;
      else if (N[i] == 0 && M[i] == 1)
        ANS.set(i);
      else if (N[i] == 1 && M[i] == 0)
        break;
    }
    if ((ANS ^ N) == M) {
      ANS.set(last_i);
      for (int i = last_i - 1; i >= 0; --i) {
        ANS.reset(i);
      }
    }
    cout << ANS.to_ullong() << endl;
  }
}
