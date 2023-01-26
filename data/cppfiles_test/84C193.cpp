#include <bits/stdc++.h>
using namespace std;
int t, N;
int main() {
  cin >> t;
  while (t-- > 0) {
    int a, b;
    cin >> a >> b;
    cout << b / (a / 2 + 1) << "\n";
  }
}
