#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int MAX = 2e5 + 5;
void solve() {
  int n, k, ans[MAX];
  pair<int, int> arr[MAX];
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(arr, arr + n);
  arr[n].first = arr[n].second == -1;
  vector<int> v, tmp;
  if (arr[0].first == arr[1].first) {
    tmp.push_back(arr[0].second);
  } else {
    v.push_back(arr[0].second);
  }
  for (int i = 1; i < n; ++i) {
    if (v.size() >= k) {
      for (int i1 = 1; i1 <= k; ++i1) {
        ans[v[v.size() - i1]] = i1;
      }
      for (int i1 = 1; i1 <= k; ++i1) v.pop_back();
    }
    if (arr[i].first == arr[i + 1].first) {
      tmp.push_back(arr[i].second);
    } else if (arr[i].first == arr[i - 1].first &&
               arr[i].first != arr[i + 1].first) {
      tmp.push_back(arr[i].second);
      if (tmp.size() >= k) {
        for (int i1 = 0; i1 < k; ++i1) {
          ans[tmp[i1]] = i1 + 1;
        }
        for (int i1 = k; i1 < tmp.size(); ++i1) {
          ans[tmp[i1]] = 0;
        }
        tmp.clear();
      } else {
        for (int i1 = 0; i1 < tmp.size(); ++i1) {
          v.push_back(tmp[i1]);
        }
        tmp.clear();
      }
    } else {
      v.push_back(arr[i].second);
    }
  }
  if (v.size() >= k) {
    for (int i = 1; i <= k; ++i) {
      ans[v[v.size() - i]] = i;
    }
    for (int i = 1; i <= k; ++i) {
      v.pop_back();
    }
  }
  for (int i = 0; i < v.size(); ++i) {
    ans[v[i]] = 0;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
