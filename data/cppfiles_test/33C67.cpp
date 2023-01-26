#include <bits/stdc++.h>
using namespace std;
template <class Temp>
vector<Temp> read(long long int n) {
  vector<Temp> input;
  for (long long int i = 0; i < n; i++) {
    Temp k;
    cin >> k;
    input.push_back(k);
  }
  return input;
}
template <class Temp>
vector<vector<Temp>> read_matrix(long long int n, long long int m) {
  vector<vector<Temp>> input(n + 1, vector<Temp>(m + 1, 0));
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      Temp k;
      cin >> k;
      input[i][j] = k;
    }
  }
  return input;
}
template <class Temp>
void print(vector<long long int> &v) {
  for (Temp a : v) {
    cout << a << " ";
  }
  cout << endl;
}
vector<long int> coor;
bool comparator(long int &i, long int &j) {
  return abs(coor[i]) > abs(coor[j]);
}
void solve() {
  int n;
  cin >> n;
  vector<long long int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long int ans = -1;
  for (int i = 1; i < n - 1; i++) {
    if (a[i - 1] <= a[i] && a[i] >= a[i + 1]) {
      long long int t = a[i] * a[i - 1];
      t = max(t, a[i] * a[i + 1]);
      ans = max(ans, t);
    }
  }
  long long int m = max(a[0] * a[1], a[n - 1] * a[n - 2]);
  ans = max(m, ans);
  cout << ans << endl;
}
void test() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  test();
}
