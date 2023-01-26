#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int seq[1001];
  int n = 1;
  int i = 1;
  while (i < 1001) {
    seq[i] = n;
    n++;
    while (n % 3 == 0 || n % 10 == 3) {
      n++;
    }
    i++;
  }
  cout << "\n";
  while (t--) {
    int k;
    cin >> k;
    cout << seq[k] << "\n";
  }
  return 0;
}
