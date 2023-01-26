#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
pair<int, int> p[N];
int n, m;
int tr[N];
vector<pair<int, int> > vec;
vector<int> nums;
int lowbit(int x) { return x & (-x); }
void add(int x, int val) {
  while (x < N) {
    tr[x] += val;
    x += lowbit(x);
  }
}
int query(int x) {
  int res = 0;
  while (x > 0) {
    res += tr[x];
    x -= lowbit(x);
  }
  return res;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++) {
      int x;
      scanf("%d", &x);
      nums.push_back(x);
      p[i] = {x, i};
    }
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= n * m; i++) {
      int x =
          lower_bound(nums.begin(), nums.end(), p[i].first) - nums.begin() + 2;
      p[i] = {x, i};
    }
    sort(p + 1, p + 1 + n * m);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
      vec.clear();
      for (int j = (i - 1) * m + 1; j <= i * m; j++) {
        vec.push_back({p[j].second, p[j].first});
      }
      sort(vec.begin(), vec.end());
      for (auto t : vec) {
        res += query(t.second - 1);
        add(t.second, 1);
      }
      for (auto t : vec) {
        add(t.second, -1);
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}
