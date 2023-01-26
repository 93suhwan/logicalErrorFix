#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i = 2;
    int count = 0;
    while (count < n) {
      cout << i << " ";
      ++count;
      ++i;
    }
    cout << endl;
  }
  return 0;
}
