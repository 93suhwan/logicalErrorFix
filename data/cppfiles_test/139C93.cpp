#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string killme[t];
  int count = 0;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    int length = s.length();
    if (length % 2 != 0) {
      killme[count] = "NO";
      count += 1;
      continue;
    }
    int mid = length / 2;
    string halfand = s.substr(0, mid);
    string half = s.substr(mid);
    if (halfand.compare(half) == 0) {
      killme[count] = "YES";
      count += 1;
    } else {
      killme[count] = "NO";
      count += 1;
    }
  }
  for (int z = 0; z < t; z++) cout << killme[z] << "\n";
  return 0;
}
