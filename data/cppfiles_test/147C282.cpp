#include <bits/stdc++.h>
using namespace std;
void solve() {
  string second;
  cin >> second;
  int n = second.size();
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (second[i] == 'N') {
      c++;
    }
  }
  if (c > 1 || c == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  long long t;
  t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
