#include <bits/stdc++.h>
using namespace std;
int bit[500009], n;
void add(int x) {
  while (x <= n) {
    bit[x]++;
    x += (x & (-x));
  }
}
int cal(int x) {
  int ans = 0;
  while (x > 0) {
    ans += bit[x];
    x -= (x & (-x));
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= n + 3; i++) bit[i] = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans += i - cal(x);
      add(x);
    }
    if (ans % 2)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
