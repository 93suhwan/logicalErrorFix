#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int a = 0;
    cin >> a;
    v.push_back(a);
  }
  int s = k / n;
  int e = k;
  int answer = INT_MAX;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (v[i] + mid > v[i + 1]) {
        ans = ans + (v[i + 1] - v[i]);
      } else {
        ans = ans + mid;
      }
    }
    ans = ans + mid;
    if (ans >= k) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  cout << s << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
