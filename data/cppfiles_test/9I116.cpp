#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const long long mod = 1e9 + 7;
vector<int> v[N];
set<int> s;
int ans[N];
int cnt[N];
struct $ {
  int x;
  int cnt;
  bool operator<($ p) const {
    if (cnt != p.cnt)
      return cnt < p.cnt;
    else
      return x < p.x;
  }
};
set<$> p;
void slove() {
  p.clear();
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    s.insert(x);
    v[x].push_back(i);
    cnt[i] = 0;
  }
  int sum = 0;
  for (int i : s) {
    sum += min(int(v[i].size()), k);
  }
  sum /= k;
  for (int i : s) {
    int len = v[i].size();
    if (len < k) {
      continue;
    }
    for (int j = 0; j < k; ++j) {
      cnt[j + 1]++;
      ans[v[i][j]] = j + 1;
    }
    for (int j = k; j < len; ++j) {
      ans[v[i][j]] = 0;
    }
  }
  for (int i = 1; i <= k; ++i) {
    p.insert(($){i, cnt[i]});
  }
  for (int i : s) {
    int len = v[i].size();
    if (len >= k) {
      continue;
    }
    set<$>::iterator it = p.begin();
    set<$> temp;
    int j;
    for (j = 0; j < len; ++j, ++it) {
      if ((*it).cnt == sum) {
        break;
      }
      temp.insert(*it);
      ans[v[i][j]] = (*it).x;
    }
    for (int pp = j; pp < len; ++pp) {
      ans[v[i][pp]] = 0;
    }
    it = p.begin();
    for (int pp = 0; pp < j; ++pp) {
      p.erase(*p.begin());
    }
    for ($ j : temp) {
      $ pp = j;
      pp.cnt++;
      p.insert(pp);
    }
  }
  for (int i : s) {
    v[i].clear();
  }
  s.clear();
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    slove();
  }
  return 0;
}
