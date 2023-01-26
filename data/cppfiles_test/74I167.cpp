#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  vector<int> v;
  if (a == b) {
    for (int i = 0; i <= a + b; i += 2) v.push_back(i);
  } else if (a == 0 or b == 0 or a % b == 0 or b % a == 0) {
    int s = abs(a - b) / 2;
    int e = ((a + b) % 2 == 0) ? 2 : 1;
    for (int i = s; i <= (a + b) - s; i += e) v.push_back(i);
  } else {
    int s = abs(a - b) / 2;
    for (int i = s; i <= (a + b) - s; i++) v.push_back(i);
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
