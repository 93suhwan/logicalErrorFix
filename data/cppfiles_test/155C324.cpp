#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<int> a;
  int n;
  a.resize(2e5);
  for (int i = 0; i < t; i++) {
    string s;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    cin >> s;
    int countForOne = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') {
        countForOne++;
      }
    }
    int countForZero = n - countForOne;
    stack<int> ones;
    stack<int> zeros;
    for (int j = 0; j < n; j++) {
      if (s[j] == '0' && countForZero < a[j]) {
        zeros.push(j);
      } else if (s[j] == '1' && countForZero >= a[j]) {
        ones.push(j);
      }
    }
    while (!ones.empty()) {
      int idx1 = ones.top();
      int idx0 = zeros.top();
      ones.pop();
      zeros.pop();
      int tmp = a[idx1];
      a[idx1] = a[idx0];
      a[idx0] = tmp;
    }
    for (int j = 0; j < n; j++) {
      cout << a[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
