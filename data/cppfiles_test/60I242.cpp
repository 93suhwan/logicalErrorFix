#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int temp = 0;
  long long int val = 1;
  for (int i = 1; i <= 9; i++) {
    temp += val;
    val *= 2;
  }
  while (t--) {
    int n;
    cin >> n;
    val = temp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      val = (val & x);
    }
    cout << val << "\n";
  }
}
