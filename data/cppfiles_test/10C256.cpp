#include <bits/stdc++.h>
const long long int mx = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vp, vpAns;
    map<int, int> mp, mpAns, mpCnt;
    int A[n + 2], x = n / k;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      vp.push_back(make_pair(A[i], i));
    }
    sort(vp.begin(), vp.end());
    int cnt = 0, cn = 0;
    for (int i = 0; i < n; i++) {
      int a = vp[i].first, b = vp[i].second;
      mp[a]++;
      if (mp[a] > k) {
        vpAns.push_back(make_pair(b, 0));
        continue;
      }
      cnt++;
      vpAns.push_back(make_pair(b, cnt));
      mpCnt[cnt]++;
      if (cnt == k) cnt = 0;
    }
    int mn = 10000000;
    for (auto u : mpCnt) {
      mn = min(mn, u.second);
    }
    sort(vpAns.begin(), vpAns.end());
    for (int i = 0; i < vpAns.size(); i++) {
      int b = vpAns[i].second;
      mpAns[b]++;
      if (mpAns[b] > mn)
        cout << 0 << ' ';
      else
        cout << vpAns[i].second << ' ';
    }
    cout << endl;
  }
  return 0;
}
