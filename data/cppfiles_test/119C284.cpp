#include <bits/stdc++.h>
using namespace std;
void so() {
  int h;
  cin >> h;
  int a[h];
  int sum = 0;
  for (int i = 0; i < h; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % h)
    cout << "1\n";
  else {
    cout << "0\n";
  }
}
int main() {
  int m;
  cin >> m;
  while (m--) {
    so();
  }
  return 0;
}
