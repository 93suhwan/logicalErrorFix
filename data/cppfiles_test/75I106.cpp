#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << "Alice"
         << "\n";
    return 0;
  }
  int i = 0;
  int j = n - 1;
  vector<int> c(1, 0);
  bool turn = true;
  while (i < j) {
    bool flag = false;
    if (c.back() < a[i]) {
      flag = true;
      c.push_back(a[i]);
      i += 1;
    }
    if (c.back() < a[j]) {
      flag = true;
      c.push_back(a[i]);
      j -= 1;
    }
    if (!flag) {
      break;
    }
    turn = !turn;
  }
  cout << (turn ? "Bob" : "Alice") << '\n';
  return 0;
}
