#include <bits/stdc++.h>
using namespace std;
struct s_ix {
  long long ix;
  long long val;
};
bool operator<(s_ix aa, s_ix bb) { return aa.val - aa.ix < bb.val - bb.ix; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n, k, nc[200200], sum, nbw, maxnbw;
    s_ix nb[200200];
    string s[200200];
    cin >> n;
    for (int j = 0; j < n; j++) cin >> s[j];
    maxnbw = 0;
    for (int l = 0; l < 26; l++) {
      nbw = 0;
      for (int j = 0; j < n; j++) {
        nb[j].val = 0;
        nb[j].ix = 0;
        for (int jj = 0; jj < s[j].length(); jj++) {
          if ((int)(s[j][jj] - 'a') == l)
            nb[j].val++;
          else
            nb[j].ix++;
        }
      }
      sort(nb, nb + n);
      reverse(nb, nb + n);
      long long nl = 0;
      nl = nb[0].val - nb[0].ix;
      int j = 0;
      while (nl > 0 and j < n) {
        j++;
        nl += nb[j].val - nb[j].ix;
        nbw++;
      }
      maxnbw = max(maxnbw, nbw);
    }
    cout << maxnbw << endl;
  }
}
