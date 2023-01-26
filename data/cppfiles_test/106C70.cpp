#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 2; i <= n + 1; i++) cout << i << " ";
    cout << endl;
  }
  return 0;
}
