#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
void debug1d(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
  cout << "\n";
}
void debug2d(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << ' ';
    cout << "\n";
  }
}
long long calc(vector<int> &arr, int ind) {
  int n = arr.size();
  if (ind == n) return 1;
  long long res = 0;
  int a, b;
  if (arr[ind] > 9) {
    a = arr[ind] - 9;
    b = 9;
    res += b - a + 1;
  } else {
    a = 0;
    b = arr[ind];
    res += b + 1;
  }
  res *= calc(arr, ind + 1);
  long long res2 = 0;
  if (n - ind > 2 && arr[ind]) {
    arr[ind + 2] += 10;
    arr[ind]--;
    if (arr[ind] > 9) {
      a = arr[ind] - 9;
      b = 9;
      res2 += b - a + 1;
    } else {
      a = 0;
      b = arr[ind];
      res2 += b + 1;
    }
    res2 *= calc(arr, ind + 1);
  }
  return res + res2;
}
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) arr[i] = s[i] - '0';
  cout << calc(arr, 0) - 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
