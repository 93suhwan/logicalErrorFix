#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 2; i < n + 2; i++) {
      cout << i << " ";
    }
    cout << endl;
  }
}
