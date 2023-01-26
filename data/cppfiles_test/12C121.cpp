#include <bits/stdc++.h>
using namespace std;
struct Comparator {
  bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
    if (lhs.first == rhs.first) return lhs.second < rhs.second;
    return lhs.first < rhs.first;
  }
};
void addLetters(char l, int amount, string& S) {
  for (int i = 0; i < amount; i++) S += l;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 0) {
    if (n % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
    return;
  }
  if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
    return;
  }
  if (n % 2 == 0 && m % 2 == 1) {
    if (k % 2 == 0) {
      if (n * (m - 1) / 2 >= k) {
        cout << "YES\n";
      } else
        cout << "NO\n";
    } else
      cout << "NO\n";
    return;
  }
  if (n % 2 == 1 && m % 2 == 0) {
    int c = m / 2;
    k -= c;
    if (k < 0) {
      cout << "NO\n";
      return;
    }
    if (k % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
    return;
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
