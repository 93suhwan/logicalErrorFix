#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    string s;
    getline(cin, s);
    vector<char> vec;
    for (int i = 0; s[i] != '\0'; i++) {
      vec.push_back(s[i]);
    }
    int times = 0;
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] == 'N') {
        times += 1;
      } else
        times += 0;
    }
    if (times == 1) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
    }
  }
  return 0;
}
