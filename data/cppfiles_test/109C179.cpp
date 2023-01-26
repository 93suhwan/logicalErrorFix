#include <bits/stdc++.h>
using namespace std;
void countdown(int n) {
  char N[n];
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  int opr = 0;
  if (N[n - 1] != '0') {
    opr += N[n - 1] - '0';
    N[n - 1] = '0';
  }
  for (int i = 0; i < n - 1; i++) {
    if (N[i] != '0') {
      opr += N[i] - '0' + 1;
      N[i] = '0';
    }
  }
  cout << opr << endl;
}
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    int n;
    cin >> n;
    countdown(n);
    t--;
  }
}
