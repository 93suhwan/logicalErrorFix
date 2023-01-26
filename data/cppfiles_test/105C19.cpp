#include <bits/stdc++.h>
using namespace std;
vector<int> v[2000005];
int a[200005], b[200005], m[200005];
int ans1[200005], ans2[200005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> d;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &a[i], &b[i], &m[i]);
      v[a[i] + b[i] - m[i]].emplace_back(i);
      d.emplace_back(a[i] + b[i] - m[i]);
    }
    sort((d).begin(), (d).end());
    d.erase(unique((d).begin(), (d).end()), d.end());
    int ans = 0;
    for (int i = 0; i < (int)(d).size(); i++) {
      int val = d[i];
      vector<pair<pair<int, int>, int> > S;
      for (int j = 0; j < (int)(v[val]).size(); j++) {
        int k = v[val][j];
        int l = max(0, a[k] - m[k]), r = a[k];
        if (b[k] - m[k] < 0) r -= abs(b[k] - m[k]);
        S.emplace_back(make_pair(make_pair(r, l), k));
      }
      sort((S).begin(), (S).end());
      int last = 0;
      for (int j = 0; j < (int)(S).size(); j++) {
        int l = S[j].first.second, r = S[j].first.first, k = S[j].second;
        if (j == 0) {
          last = r;
          ans1[k] = last;
          ans2[k] = b[k] - (m[k] - (a[k] - last));
          ans++;
        } else {
          if (!(l <= last && last <= r)) {
            last = r;
            ans++;
          }
          ans1[k] = last;
          ans2[k] = b[k] - (m[k] - (a[k] - last));
        }
      }
    }
    for (int i = 0; i < (int)(d).size(); i++) {
      int val = d[i];
      v[val].clear();
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", a[i] - ans1[i], b[i] - ans2[i]);
    }
  }
}
