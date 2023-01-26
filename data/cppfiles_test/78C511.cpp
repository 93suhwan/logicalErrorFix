#include <bits/stdc++.h>
using namespace std;
void solution() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  if (b % 2 == 0) {
    ans = b / 2 + 1;
  } else {
    ans = ceil(b / 2.0f);
  }
  if (ans >= a) {
    cout << b % ans << "\n";
  } else {
    cout << b - a << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
