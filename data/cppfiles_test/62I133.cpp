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
  vector<int> arr(n + 1);
  for (int i = 1; i < n + 1; i++) cin >> arr[i];
  vector<vector<int> > grph(n + 2);
  for (int i = 1; i < n; i++) grph[i].push_back(i + 1);
  for (int i = 1; i < arr.size(); i++) {
    arr[i] ? grph[n + 1].push_back(i) : grph[i].push_back(n + 1);
  }
  if (binary_search(grph[n + 1].begin(), grph[n + 1].end(), 1)) {
    cout << n + 1 << ' ';
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << "\n";
    return;
  } else if (binary_search(grph[n].begin(), grph[n].end(), n + 1)) {
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << n + 1;
    cout << "\n";
    return;
  } else {
    for (int i = 2; i < n; i++) {
      if (binary_search(grph[i].begin(), grph[i].end(), n + 1) &&
          binary_search(grph[n + 1].begin(), grph[n + 1].end(), i + 1)) {
        for (int j = 1; j <= i; j++) cout << j << ' ';
        cout << n + 1 << "\n";
        for (int j = i; j <= n; j++) cout << j << ' ';
        cout << "\n";
        return;
      }
    }
  }
  cout << -1 << "\n";
}
int main() {
  int t = 1, cas = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
