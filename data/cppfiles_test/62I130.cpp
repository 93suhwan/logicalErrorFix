#include <bits/stdc++.h>
using namespace std;
int x4[] = {1, 0, -1, 0};
int y4[] = {0, -1, 0, 1};
int x8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int y8[] = {0, -1, -1, -1, 0, 1, 1, 1};
void prntVec(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
    i + 1 == a.size() ? cout << "\n" : cout << ' ';
  }
}
const long long mod = 1e9 + 7;
long long n, k, m;
long long a, b, c, d;
void solve() {
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr) cin >> i;
  for (int i = 1; i <= n + 1; i++) cout << i << ' ';
  cout << "\n";
}
int main() {
  int t = 1, cas = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
