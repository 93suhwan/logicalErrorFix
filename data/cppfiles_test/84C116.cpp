#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    int len = n / 2 + 1;
    cout << s / len << endl;
  }
  return 0;
}
