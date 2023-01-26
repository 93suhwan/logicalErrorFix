#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
  vector<char> a;
  for (int i = 0; i < n; i++) {
    a.push_back('(');
    a.push_back(')');
  }
  for (int i = 0; i < 2 * n; i++) {
    cout << a[i];
  }
  cout << "\n";
  for (int i = 2; i < 2 * n; i += 2) {
    cout << a[i];
    for (int j = 0; j < 2 * n; j++) {
      if (j != i) {
        cout << a[j];
      }
    }
    cout << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }
  return 0;
}
