#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, sum = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
  }
  if (sum % n == 0) {
    cout << 0;
  } else {
    cout << 1;
  }
  cout << endl;
}
