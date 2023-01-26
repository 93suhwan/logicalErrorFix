#include <bits/stdc++.h>
using namespace std;
class BIT {
 private:
  vector<long long> tree;
  int n;
  int LSOne(int x) { return x & (-x); }

 public:
  BIT(int x) {
    n = x;
    tree.resize(n + 1);
  }
  long long sum(int a) {
    long long sum = 0;
    for (; a > 0; a -= LSOne(a)) sum += tree[a];
    return sum;
  }
  long long sum(int a, int b) { return sum(b) - (a == 1 ? 0 : sum(a - 1)); }
  void update(int p, long long v) {
    for (; p < n + 1; p += LSOne(p)) tree[p] += v;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> mp;
    for (int i = 0; i < (int)n; i++) {
      cin >> nums[i];
      mp[nums[i]] = 1;
    }
    int pt = 1;
    for (auto &i : mp) {
      mp[i.first] = pt++;
    }
    for (int i = 0; i < (int)n; i++) nums[i] = mp[nums[i]];
    deque<int> q;
    q.push_back(nums[0]);
    BIT tree(n);
    tree.update(nums[0], 1);
    long long ans = 0;
    for (int i = 1; i < (int)n; i++) {
      int bef = tree.sum(1, nums[i] - 1), af = tree.sum(nums[i] + 1, n);
      if (bef >= af)
        q.push_back(nums[i]);
      else
        q.push_front(nums[i]);
      ans += min(bef, af);
      tree.update(nums[i], 1);
    }
    cout << ans << '\n';
  }
}
