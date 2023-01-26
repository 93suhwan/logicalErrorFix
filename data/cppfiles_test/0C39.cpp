#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
string arr[MAX + 1];
int n, m;
bool compare(int i, int j) {
  for (int z = 0; z < m; z++) {
    if (arr[i][z] != arr[j][z]) {
      if (z % 2 == 0) {
        return arr[i][z] < arr[j][z];
      } else
        return arr[i][z] > arr[j][z];
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int j = 1; j <= n; j++) cin >> arr[j];
  vector<int> v(n + 1);
  for (int j = 1; j <= n; j++) v[j] = j;
  sort(v.begin(), v.end(), compare);
  for (int j = 1; j <= n; j++) cout << v[j] << ' ';
  cout << '\n';
  return;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
