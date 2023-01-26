#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    int length = s.length();
    if (length % 2 != 0) {
      cout << "NO";
      continue;
    }
    int mid = length / 2;
    string halfand = s.substr(0, mid);
    string half = s.substr(mid);
    if (halfand.compare(half) == 0) {
      cout << "YES";
    } else
      cout << "NO";
  }
  return 0;
}
