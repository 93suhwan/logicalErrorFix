#include <bits/stdc++.h>
#pragma GCC optimize("O4,unroll-loops,no-stack-protector")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int n, m;
int arr[13][10005];
int e[13];
vector<int> ans(10005), Ans(10005);
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> e[i];
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        char c;
        cin >> c;
        arr[i][j] = (c == '1');
      }
    }
    int best = -1;
    for (int i = 0; i <= m; i++) {
      ans[i] = 0;
      Ans[i] = 0;
    }
    for (int bit = 0; bit < (1 << n); bit++) {
      vector<pair<long long, long long> > cnt1(m + 2), cnt2(m + 2);
      cnt1[0] = make_pair(-1, -1);
      cnt2[0] = make_pair(-1, -1);
      for (int i = 1; i <= m; i++) {
        cnt1[i].second = i;
        cnt2[i].second = i;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++)
          if (arr[i][j]) {
            if ((1 << i) & bit)
              cnt1[j].first++;
            else
              cnt1[j].first--;
          }
      }
      sort(cnt1.begin() + 1, cnt1.begin() + 1 + m);
      for (int j = 1; j <= m; j++) {
        ans[cnt1[j].second] = j;
      }
      int res = 0;
      for (int i = 0; i < n; i++) {
        int now = 0;
        for (int j = 1; j <= m; j++)
          if (arr[i][j]) now += ans[j];
        res += abs(now - e[i]);
      }
      if (res > best) {
        best = res;
        Ans = ans;
      }
    }
    for (int i = 1; i <= m; i++) cout << Ans[i] << " ";
    cout << "\n";
  }
}
