#include <bits/stdc++.h>
using namespace std;
const long long INFLL = 1e18;
const int INF = 1e9;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 1e5 + 5;
int read() {
  char k = getchar();
  int x = 0;
  while (k < '0' || k > '9') k = getchar();
  while (k >= '0' && k <= '9') x = x * 10 + k - '0', k = getchar();
  return x;
}
void insertionSort(int arr[], int n, vector<pair<int, int>> &ans) {
  int key, j;
  for (int i = n - 2; i >= 0; i--) {
    key = arr[i];
    j = i + 1;
    while (j < n - 1 && arr[j] < key) {
      arr[j - 1] = arr[j];
      j++;
    }
    if (j != i + 1) ans.push_back({j + 2, i + 1});
    arr[j - 1] = key;
  }
}
void solve() {
  int n;
  cin >> n;
  ;
  int a[n];
  for (int i = 0; i <= n - 1; i++) cin >> a[i];
  ;
  vector<pair<pair<int, int>, int>> ans;
  for (int i = 0; i <= n - 1; i++) {
    int mn = INT_MAX, mi = i;
    for (int j = i; j <= n - 1; j++) {
      if (a[j] < mn) {
        mn = a[j];
        mi = j;
      }
    }
    if (mi != i) {
      ans.push_back({{i, mi}, mi - i});
      for (int k = mi - 1; k >= i; k--) swap(a[k], a[k + 1]);
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans)
    cout << i.first.first + 1 << " " << i.first.second + 1 << " " << i.second
         << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
