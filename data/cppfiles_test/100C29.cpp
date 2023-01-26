#include <bits/stdc++.h>
using namespace std;
long long casenum = 1;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void rf() {}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int pos[1005];
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ret = a[0];
  for (int i = 0; i < n - 1; ++i) {
    ret = max(ret, a[i + 1] - a[i]);
  }
  cout << ret << endl;
}
int main() {
  fast();
  rf();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
