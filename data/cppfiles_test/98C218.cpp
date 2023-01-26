#include <bits/stdc++.h>
using namespace std;
string a, b;
int func(char q) {
  for (int i = 0; i < a.size(); i++)
    if (a[i] == q) return i;
}
void solve() {
  cin >> a >> b;
  int sum = 0;
  for (int i = 1; i < b.size(); i++)
    sum += int(abs(func(b[i]) - func(b[i - 1])));
  cout << sum;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
