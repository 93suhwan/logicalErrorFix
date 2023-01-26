#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int num;
  cin >> num;
  if (num % 2 == 0)
    cout << 2 << " " << num << endl;
  else if (num % 2 != 0)
    cout << 2 << " " << num - 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int testCases;
  cin >> testCases;
  while (testCases--) {
    solve();
  }
  return 0;
}
