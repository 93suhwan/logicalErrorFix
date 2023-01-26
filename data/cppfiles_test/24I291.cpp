#include <bits/stdc++.h>
using namespace std;
void solve(int num) {
  if (num == 9) {
    cout << 1 << endl;
    return;
  }
  cout << num / 10 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int s;
    cin >> s;
    solve(s);
  }
}
