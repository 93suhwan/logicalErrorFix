#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    m++;
    string sn, sm;
    while (n > 0) {
      if (n % 2 == 1)
        sn = sn + '1';
      else
        sn = sn + '0';
      n = n / 2;
    }
    reverse(sn.begin(), sn.end());
    while (m > 0) {
      if (m % 2 == 1)
        sm = sm + '1';
      else
        sm = sm + '0';
      m = m / 2;
    }
    reverse(sm.begin(), sm.end());
    while (sn.size() < sm.size()) sn = '0' + sn;
    while (sm.size() < sn.size()) sm = '0' + sm;
    string ans;
    for (int j = 0; j < sm.size(); j++) {
      if (sm[j] == '1' && sn[j] == '0')
        ans = ans + '1';
      else
        ans = ans + '0';
    }
    long long num = 0;
    long long k = 1;
    for (int j = ans.size() - 1; j >= 0; j--) {
      if (ans[j] == '1') num = num + k;
      k = k * 2;
    }
    cout << num << endl;
  }
}
