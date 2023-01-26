#include <bits/stdc++.h>
const double eps = 1e-9;
const int inf = 1000000005;
const long long llinf = 1000000000000000005LL;
using namespace std;
int TC;
vector<vector<long int>> semiSolve1(long int arr[], int n) {
  vector<vector<long int>> vv;
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        vector<long int> v{j + 1, j + 2, 1};
        vv.push_back(v);
      }
  return vv;
}
vector<vector<long int>> semiSolve2(long int arr[], int n) {
  vector<vector<long int>> vv;
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
    if (j + 1 != i) {
      vector<long int> v{j + 2, i + 1, 1};
      vv.push_back(v);
    }
  }
  return vv;
}
void solve() {
  int n;
  cin >> n;
  long int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<long int>> vv = semiSolve2(a, n);
  cout << vv.size() << '\n';
  for (auto x : vv) {
    for (int i = 0; i < x.size(); i++) {
      cout << x[i] << " ";
    }
    cout << '\n';
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> TC;
  while (TC--) {
    solve();
  }
}
