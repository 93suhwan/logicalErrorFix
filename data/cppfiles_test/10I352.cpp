#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
unordered_map<int, int> hh;
int nums[N];
vector<int> aa[N];
int res[N];
bool st[N];
int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    memset(res, 0, sizeof res);
    memset(st, 0, sizeof st);
    for (int i = 0; i < N; i++) aa[i].clear();
    hh.clear();
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      nums[i] = x;
      hh[x]++;
      aa[x].push_back(i);
    }
    int q = 1;
    for (int i = 0; i < n; i++) {
      if (res[i] == 0) {
        if (!st[nums[i]] && hh[nums[i]] >= k) {
          int p = 0;
          for (int j = 1; j <= k; j++) {
            res[aa[nums[i]][p++]] = j;
          }
          st[nums[i]] = true;
        } else if (hh[nums[i]] < k) {
          res[i] = q++;
          if (q > k) q = 1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
