#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t >= 1) {
    long long int n;
    cin >> n;
    long long int cube, square;
    cube = cbrt(n);
    square = sqrt(n);
    set<int> s;
    for (int i = 1; i <= cube; i++) {
      s.insert(i * i * i);
    }
    for (int i = 1; i <= square; i++) {
      s.insert(i * i);
    }
    cout << s.size() << endl;
    t--;
  }
  return 0;
}
