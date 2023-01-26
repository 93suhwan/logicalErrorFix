#include <bits/stdc++.h>
using namespace std;
string fun(vector<int> a) {
  sort(a.begin(), a.end());
  if (a[1] != a[2]) {
    if (a[0] + a[1] == a[2]) {
      return "YES";
    } else {
      return "NO";
    }
  } else {
    if (a[0] > 1) {
      return "YES";
    } else {
      return "NO";
    }
  }
  return "";
}
int main() {
  int t;
  cin >> t;
  vector<int> a(3);
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[j];
    }
    cout << fun(a) << endl;
  }
  return 0;
}
