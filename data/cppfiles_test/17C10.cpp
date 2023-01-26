#include <bits/stdc++.h>
const int mod = 1000000007;
const int modx = 998244353;
const long long inf = (1e18);
using namespace std;
void inputfromtext() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
class fenwickTree {
 public:
  long long len;
  vector<long long> BIT;
  fenwickTree(long long _len, vector<long long> arr) {
    len = _len;
    BIT.resize(len + 5);
  }
  void buildBIT(vector<long long> arr) {
    for (auto i = 0; i < len; i++) updateBIT(i, arr[i]);
  }
  void updateBIT(long long index, long long val) {
    index = index + 1;
    while (index <= len) {
      BIT[index] += val;
      index = index + (index & (-index));
    }
    return;
  }
  long long getBITSum(long long index) {
    long long sumTillIndex = 0;
    index = index + 1;
    while (index >= 1) {
      sumTillIndex += BIT[index];
      index = index - (index & (-index));
    }
    return sumTillIndex;
  }
  long long queryBIT(long long left, long long right) {
    long long leftSum = 0, rightSum = 0;
    rightSum = getBITSum(right);
    if (left != 0) leftSum = getBITSum(left - 1);
    return rightSum - leftSum;
  }
};
void thunder() {
  long long n;
  cin >> n;
  vector<long long> a(n), c;
  for (auto i = 0; i < n; i++) cin >> a[i];
  c = a;
  sort(a.begin(), a.end());
  map<long long, long long> m1, m2;
  long long cnt = 1;
  for (auto i = 0; i < n; i++) {
    if (m1.find(a[i]) != m1.end()) {
      a[i] = m1[a[i]];
    } else {
      m1[a[i]] = cnt;
      m2[cnt] = a[i];
      a[i] = cnt++;
    }
  }
  long long maxx = a.back() + 5, ans = 0;
  fenwickTree bit(maxx + 1, a);
  a = c;
  deque<long long> q;
  for (auto i = 0; i < n; i++) {
    bit.updateBIT(m1[a[i]], 1);
    long long inv = bit.getBITSum(m1[a[i]] - 1);
    inv = min(inv, bit.getBITSum(maxx) - bit.getBITSum(m1[a[i]]));
    ans += inv;
  }
  cout << ans << "\n";
  return;
}
int main() {
  inputfromtext();
  long long tt = 1;
  cin >> tt;
  for (long long testcase = 1; testcase <= tt; testcase++) {
    thunder();
  }
  return 0;
}
