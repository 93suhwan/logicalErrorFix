#include <bits/stdc++.h>
using namespace std;
bool big(pair<long long int, long long int>& a,
         pair<long long int, long long int>& b) {
  return a.second < b.second;
}
void Solve() {
  long long int a, b;
  cin >> a >> b;
  if (a == b && a == 0)
    cout << 0 << '\n';
  else if (a == b)
    cout << 1 << '\n';
  else {
    if (abs(a - b) % 2 == 0)
      cout << 2 << '\n';
    else
      cout << -1 << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long int T;
  cin >> T;
  while (T--) Solve();
  return 0;
}
