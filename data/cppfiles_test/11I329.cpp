#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long m, n, i, j, k, cnt1 = 0, curalp, others, cntc = 0, mx = 0, x,
                             cnt3 = 0, idx, sum = 0, l, cnt4 = 0;
    cin >> n;
    string s[n + 1];
    vector<pair<long long, long long>> vp;
    long long cnt[6];
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < s[i].size(); j++) {
        cnt[s[i][j] - 'a']++;
      }
    }
    sum = cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4];
    for (x = 0; x < 5; x++) {
      curalp = cnt[x];
      others = sum - curalp;
      if (curalp > others) {
        mx = n;
      } else {
        for (i = 0; i < n; i++) {
          cntc = 0;
          for (j = 0; j < s[i].size(); j++) {
            k = s[i][j] - 'a';
            if (k == x) {
              cntc++;
            }
          }
          l = s[i].size();
          vp.push_back(make_pair(l - cntc, cntc));
        }
        sort(vp.begin(), vp.end());
        idx = n - 1;
        cnt4 = 0;
        while (curalp <= others && idx > 0) {
          if (vp[idx].first != vp[idx].second) {
            curalp = curalp - vp[idx].second;
            others = others - vp[idx].first;
            cnt4++;
          }
          idx--;
        }
        if (curalp > others) {
          mx = max(mx, n - cnt4);
        }
        vp.clear();
      }
    }
    cout << mx << endl;
  }
}
