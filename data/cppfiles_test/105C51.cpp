#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 0x3f3f3f3f;
long long inf = pow(10, 18);
long long modulo = 998244353;
void deal() {
  long long t;
  cin >> t;
  for (long long l = 0; l < t; l++) {
    long long n;
    cin >> n;
    vector<vector<long long> > arr(n, vector<long long>(3));
    map<long long, vector<long long> > all;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < 3; j++) {
        cin >> arr[i][j];
      }
      all[arr[i][2] - (arr[i][0] + arr[i][1])].push_back(i);
    }
    vector<pair<long long, long long> > ans(n);
    long long tot = n;
    for (auto& el : all) {
      vector<vector<long long> > sms;
      for (auto& id : el.second) {
        long long mn, mx;
        long long ai = arr[id][0], bi = arr[id][1], mi = arr[id][2];
        if (ai >= mi) {
          mn = ai - mi;
        } else {
          mn = 0;
        }
        if (bi >= mi) {
          mx = ai;
        } else {
          mx = ai - (mi - bi);
        }
        sms.push_back(vector<long long>({mn, mx, id}));
      }
      sort(sms.begin(), sms.end());
      {
        long long st = 0;
        long long sz = sms.size();
        while (st < sz) {
          long long lim = sms[st][1];
          long long nd = st;
          while (nd < sz && sms[nd][0] <= lim) {
            lim = min(lim, sms[nd][1]);
            ++nd;
          }
          long long opt = sms[nd - 1][0];
          for (long long i = st; i < nd; i++) {
            long long id = sms[i][2];
            long long eat = arr[id][0] - opt;
            long long mi = arr[id][2];
            long long left = mi - eat;
            ans[id].first = eat, ans[id].second = left;
          }
          tot -= (nd - st - 1);
          st = nd;
        }
      }
    }
    cout << tot << '\n';
    for (long long i = 0; i < n; i++) {
      cout << ans[i].first << " " << ans[i].second << '\n';
    }
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  deal();
}
