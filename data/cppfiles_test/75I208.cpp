#include <bits/stdc++.h>
using namespace std;
int give(vector<int> v) {
  int prev = v.back();
  int cntr = 1;
  for (int i = v.size() - 2; i >= 0; i--) {
    if (v[i] <= prev) {
      break;
    }
    cntr++;
  }
  return cntr;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  int myMax = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    myMax = max(myMax, v[i]);
  }
  if (v.back() == myMax || v[0] == myMax) {
    cout << "Alice";
    return 0;
  }
  int a = give(v);
  reverse(v.begin(), v.end());
  int b = give(v);
  reverse(v.begin(), v.end());
  if (a % 2 == 0 && b % 2 == 0) {
    cout << "Bob";
    return 0;
  }
  if (a % 2 == 1 && b % 2 == 1) {
    cout << "Alice";
    return 0;
  }
  if (a % 2 == 1 && v[0] <= v.back()) {
    cout << "Alice";
    return 0;
  }
  if (b % 2 == 1 && v.back() <= v[0]) {
    cout << "Alice";
    return 0;
  }
  cout << "Alice";
  return 0;
}
