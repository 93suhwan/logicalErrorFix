#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int oneB = n / 3;
    cout << oneB << " " << ceil((n - oneB) / 2.0) << endl;
  }
  return 0;
}
