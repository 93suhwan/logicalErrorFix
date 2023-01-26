#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll diff = abs(a - b);
    if (diff <= ceil(max(a, max(b, c)) / 2)) {
      cout << -1 << '\n';
      continue;
    }
    if (c - diff > 0) {
      if (c - diff != a && c - diff != b) {
        cout << c - diff << '\n';
        continue;
      }
    }
    if (diff >= ceil((c + diff) / 2)) {
      if (c + diff != a && c + diff != b) {
        cout << c + diff << '\n';
        continue;
      }
    }
    cout << -1 << '\n';
  }
}
