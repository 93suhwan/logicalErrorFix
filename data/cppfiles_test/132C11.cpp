#include <bits/stdc++.h>
using namespace std;
void solve() {
  int v[7];
  for (int i = 0; i < 7; i++) cin >> v[i];
  cout << v[0] << " " << v[1] << " ";
  if (v[0] + v[1] == v[2]) {
    cout << v[3];
  } else
    cout << v[2];
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
