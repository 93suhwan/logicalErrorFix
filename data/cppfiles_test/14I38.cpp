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
void insertionSort(int arr[], int n, vector<pair<int, int> > &ans) {
  int key, j;
  for (int i = 1; i <= n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    if (j != i - 1) ans.push_back({j + 2, i + 1});
    arr[j + 1] = key;
  }
}
void solve() {
  int n;
  cin >> n;
  ;
  int a[n];
  for (int i = 0; i <= n - 1; i++) cin >> a[i];
  ;
  vector<pair<int, int> > ans;
  insertionSort(a, n, ans);
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i.first << " " << i.second << " 1\n";
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
