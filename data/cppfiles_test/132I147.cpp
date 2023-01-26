#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int a[N];
void solve() {
  for (int i = 1; i <= 7; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= 3; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  exit(0);
}
