#include <bits/stdc++.h>
const int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};
const int x_dir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int y_dir[] = {-1, 0, 1, -1, 1, -1, 0, 1};
using namespace std;
int solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i += 1) {
    cin >> a[i];
  };
  long long maxa = a[0];
  for (int i = 0; i < n; i++) {
    maxa = max(maxa, a[i]);
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (a[i] > a[n - 1]) {
      v.push_back(a[i]);
    }
  }
  if (v.size() == 0) {
    cout << 0 << "\n";
    return 0;
  }
  maxa = v.back();
  int c = 1;
  for (int i = v.size() - 2; i >= 0; i--) {
    if (v[i] > maxa) {
      maxa = v[i];
      c++;
    }
  }
  cout << c << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
