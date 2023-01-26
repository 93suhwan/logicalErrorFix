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
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int kk = n / 2;
  int mx;
  mx = a[n - 1];
  for (int i = 0; i < kk; i++) {
    cout << a[i] << " " << mx << endl;
  }
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
