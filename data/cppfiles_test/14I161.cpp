#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
const long long MX = 2e5 + 105;
int ara[55], n;
int sorted[55];
void shift(int l, int r, int d) {
  int prev = ara[l];
  ara[l] = ara[r];
  for (int i = 2; i <= n; i++) {
    int temp = prev;
    prev = ara[i];
    ara[i] = temp;
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ara[i];
    sorted[i] = ara[i];
  }
  sort(sorted + 1, sorted + n + 1);
  vector<pair<int, pair<int, int>>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (ara[j] == sorted[i]) {
        if (i != j) {
          ans.push_back({i, {j, j - i}});
        }
        break;
      }
    }
  }
  for (auto x : ans)
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
