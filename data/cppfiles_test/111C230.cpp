#include <bits/stdc++.h>
using namespace std;
void print(int n) {
  for (int i = 0; i < n; i++) cout << "(";
  for (int i = 0; i < n; i++) cout << ")";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      print(i);
      print(n - i);
      cout << "\n";
    }
  }
}
