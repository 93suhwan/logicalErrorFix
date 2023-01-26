#include <bits/stdc++.h>
using namespace std;
int arr[500005], brr[500005];
pair<int, int> parr[500005];
int ord[500005];
int dfs(int idx) {
  if (ord[idx] != 0) return 0;
  int ret = 1;
  vector<int> same_ord;
  int nex = idx;
  while (brr[nex] != idx) {
    nex = brr[nex];
    same_ord.push_back(nex);
    ret += 1;
  }
  for (int i = 0; i < same_ord.size(); i++) {
    ord[same_ord[i]] = ret;
  }
  ord[idx] = ret;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> parr[i].first;
      parr[i].second = i;
      ord[i + 1] = 0;
    }
    sort(parr, parr + n);
    int ev = 0;
    for (int i = 0; i < n - 1; i++) {
      if (parr[i].first == parr[i + 1].first) {
        goto YES;
      }
    }
    for (int i = 0; i < n; i++) {
      arr[i + 1] = parr[i].second + 1;
    }
    for (int i = 1; i <= n; i++) {
      brr[arr[i]] = i;
    }
    for (int i = 1; i < n + 1; i++) {
      int x = dfs(i);
      if (x == 0)
        continue;
      else {
        if (x % 2 == 0) ev += 1;
      }
    }
  YES:
    if (ev % 2 == 0)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
