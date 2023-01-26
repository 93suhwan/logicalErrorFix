#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int Z = 2e5 + 5;
int cnt[Z];
int ans[Z];
int min(int x1, int x2) {
  if (x1 > x2)
    return x2;
  else
    return x1;
}
int max(int x1, int x2) {
  if (x1 < x2)
    return x2;
  else
    return x1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    vector<pair<int, int> > v;
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
      int num;
      scanf("%d", &num);
      if (cnt[num] < k) {
        v.push_back({num, i});
      }
      cnt[num]++;
    }
    sort(v.begin(), v.end());
    int s = v.size();
    for (int i = 0; i < s / k * k; i++) {
      ans[v[i].second] = i % k + 1;
    }
    for (int i = 1; i <= n; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
}
