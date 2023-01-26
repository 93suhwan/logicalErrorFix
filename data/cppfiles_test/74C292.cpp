#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b;
  cin >> a >> b;
  long long int d = abs(a - b);
  d = d / 2;
  vector<int> arr;
  if ((a + b) % 2 == 0) {
    for (int i = d; i <= (a + b - d); i += 2) arr.push_back(i);
  } else {
    for (int i = d; i <= (a + b - d); i += 1) arr.push_back(i);
  }
  cout << arr.size() << endl;
  for (auto i : arr) cout << i << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t, i = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
