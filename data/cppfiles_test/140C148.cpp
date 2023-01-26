#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int x = 1;
    set<long long> s;
    while (x * x <= n) {
      if (x * x * x <= n) s.insert(x * x * x);
      s.insert(x * x);
      x++;
    }
    cout << s.size() << endl;
  }
}
