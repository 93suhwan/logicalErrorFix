#include <bits/stdc++.h>
using namespace std;
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
  } else {
    cout << "Bob";
  }
}
