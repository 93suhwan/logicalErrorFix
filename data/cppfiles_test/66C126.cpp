#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void debug(T... args) {
  ((cerr << args << " "), ...);
}
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T... args) {
  ((cout << args << " "), ...);
}
void solve() {
  int k;
  read(k);
  int ans = 0;
  int curr = 0;
  for (int i = 0; i < k; i++) {
    curr++;
    if (curr % 3 == 0 || curr % 10 == 3) curr++;
    if (curr % 3 == 0 || curr % 10 == 3) curr++;
  }
  cout << curr << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  read(t);
  while (t--) {
    solve();
  }
  return 0;
}
