#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 9;
const long long N = 2e18 + 9;
int tc;
int n, m;
int arr[55];
int sorted[55];
int main() {
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", arr + i);
      sorted[i] = arr[i];
    }
    sort(sorted, sorted + n);
    vector<pair<int, pair<int, int> > > ans;
    for (int i = 0; i < n; ++i) {
      if (arr[i] == sorted[i]) continue;
      int lo = i;
      int hi = i;
      for (int j = i + 1; j < n; ++j) {
        if (arr[j] == sorted[i]) {
          hi = j;
          break;
        }
      }
      int iter = (hi + 1) - (lo + 1);
      int prev = arr[i];
      arr[i] = sorted[i];
      for (int k = lo + 1; iter--; ++k) {
        int temp = arr[k];
        arr[k] = prev;
        prev = temp;
      }
      ans.push_back(make_pair((hi + 1) - (lo + 1), make_pair(lo + 1, hi + 1)));
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i].second.first << " " << ans[i].second.second << " "
           << ans[i].first << endl;
    }
  }
  return 0;
}
