#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = count(s.begin(), s.end(), 'N');
    if (a == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
