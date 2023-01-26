#include <bits/stdc++.h>
using namespace std;
int n;
void sol(int tc) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) cout << "(";
    for (int j = 0; j < i + 1; j++) cout << ")";
    int tmp = i;
    for (int j = 0; j < n - tmp - 1; j++) cout << "()";
    cout << "\n";
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) sol(0);
  return 0;
}
