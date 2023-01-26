#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<int> v;
  int min = 999999999;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (min > x) min = x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int i = 0, k = 0; k < n / 2; i++) {
    if (v[i] != min) {
      cout << v[i] << " " << min << endl;
      k++;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
