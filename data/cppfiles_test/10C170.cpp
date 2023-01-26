#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
unordered_map<int, int> hh;
struct node {
  int val, pos;
  bool operator<(const node &a) const { return val < a.val; }
} nodes[N];
int res[N];
int cnt[N];
int nums[N];
set<int> nn;
int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    hh.clear();
    nn.clear();
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      hh[nums[i]]++;
      nodes[i] = {nums[i], i};
      nn.insert(nums[i]);
    }
    sort(nodes, nodes + n);
    int tot = 0;
    for (auto x : nn) {
      if (hh[x] < k) tot = tot + hh[x];
    }
    tot = tot / k * k;
    int p = 1;
    memset(res, 0, sizeof res);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
      if (hh[nodes[i].val] >= k && cnt[nodes[i].val] < k) {
        cnt[nodes[i].val]++;
        res[nodes[i].pos] = cnt[nodes[i].val];
      } else if (hh[nodes[i].val] <= k && tot > 0) {
        res[nodes[i].pos] = p;
        p++;
        if (p > k) p = 1;
        tot--;
      }
    }
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    cout << endl;
  }
  return 0;
}
