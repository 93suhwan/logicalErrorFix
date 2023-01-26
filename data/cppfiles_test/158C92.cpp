#include <bits/stdc++.h>
using namespace std;
long long a[14][10004];
long long n, m;
long long x[15];
long long cn[10004];
long long recn[45];
long long pval;
vector<pair<long long, long long> > chist;
long long bore[300005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (long long i = 1; i <= m; i++) cn[i] = 0;
    pval = 0;
    for (long long i = 0; i <= 45; i++) recn[i] = 0;
    for (long long i = 0; i <= n - 1; i++) {
      cin >> x[i];
      pval -= x[i];
    }
    for (long long i = 0; i <= n - 1; i++)
      for (long long j = 1; j <= m; j++) {
        char c;
        cin >> c;
        long long vl = 0;
        if (c == '1') vl = 1;
        a[i][j] = vl;
        cn[j] += vl;
      }
    for (long long j = 1; j <= m; j++) {
      ++recn[cn[j] + 15];
    }
    long long ans = (long long)-1e18;
    long long old = 0;
    long long mask;
    for (long long dimw = 0; dimw <= (1 << n) - 1; dimw++) {
      long long vl = dimw ^ (dimw >> 1);
      for (long long i = 0; i <= n - 1; i++)
        if ((old ^ vl) & (1 << i)) {
          long long mval = ((old & (1 << i)) > 0);
          if (mval) {
            pval -= x[i] * 2;
          }
          if (mval == 0) {
            mval = -1;
            pval += x[i] * 2;
          }
          for (long long j = 1; j <= m; j++)
            if (a[i][j]) {
              --recn[cn[j] + 15];
              cn[j] += mval * 2;
              ++recn[cn[j] + 15];
            }
        }
      long long res = pval;
      long long mole = m;
      for (long long i = 44; i >= 0; i--)
        if (recn[i]) {
          long long fole = i - 15;
          long long bon = recn[i] * (mole * 2 - recn[i] + 1) / 2;
          mole -= recn[i];
          res += fole * bon;
        }
      old = vl;
      if (res >= ans) {
        ans = res;
        mask = vl;
      }
    }
    chist.clear();
    for (long long j = 1; j <= m; j++) cn[j] = 0;
    for (long long i = 0; i <= n - 1; i++) {
      bool bl = (mask & (1 << i)) > 0;
      for (long long j = 1; j <= m; j++)
        if (a[i][j]) {
          if (bl)
            --cn[j];
          else
            ++cn[j];
        }
    }
    for (long long j = 1; j <= m; j++)
      chist.push_back(pair<long long, long long>(cn[j], j));
    sort(chist.begin(), chist.end());
    long long cnt = 0;
    for (auto cl : chist) {
      bore[cl.second] = ++cnt;
    }
    for (long long i = 1; i <= m; i++) cout << bore[i] << " ";
    cout << "\n";
  }
}
