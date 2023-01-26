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
    long long n, k, sum, nbw, maxnbw;
    cin >> n;
    vector<s_ix> nb(n);
    vector<string> s(n);
    for (int j = 0; j < n; j++) cin >> s[j];
    maxnbw = 0;
    for (int l = 0; l < 26; l++) {
      nbw = 0;
      for (int j = 0; j < n; j++) {
        nb[j].val = 0;
        nb[j].ix = 0;
        for (int jj = 0; jj < s[j].size(); jj++) {
          if ((int)(s[j][jj] - 'a') == l)
            nb[j].val++;
          else
            nb[j].ix++;
        }
      }
      sort(nb.begin(), nb.end());
      reverse(nb.begin(), nb.end());
      long long nl = 0;
      int j = 0;
      while (j < n) {
        nl += nb[j].val - nb[j].ix;
        if (nl <= 0) break;
        j++;
        nbw++;
      }
      maxnbw = max(maxnbw, nbw);
    }
    cout << maxnbw << endl;
  }
}
