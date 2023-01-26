#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 1;
struct node {
  long long num, index, order;
};
bool cmpnum(node &a, node &b) { return a.num < b.num; }
bool cmporder(node &a, node &b) { return a.order < b.order; }
node nums[maxn];
int main() {
  long long t, n, k;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> n >> k;
    long long p = 0;
    long long last = 0;
    for (long long j = 0; j < n; j++) {
      cin >> nums[j].num;
      nums[j].order = j;
    }
    sort(nums, nums + n, cmpnum);
    for (long long j = 0; j < n; j++) {
      nums[j].index = j;
    }
    sort(nums, nums + n, cmporder);
    for (long long j = 0; j < n; j++) {
      if (j == 0) {
        p++;
      } else {
        if (nums[j].index != nums[j - 1].index + 1) p++;
      }
    }
    if (p <= k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
