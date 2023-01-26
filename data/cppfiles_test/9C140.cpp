#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    float k = 0;
    unordered_map<char, int> temp;
    for (auto it = s.begin(); it != s.end(); it++) {
      if (temp.find(*it) == temp.end()) {
        temp[*it] = 1;
      } else {
        if (temp[*it] == 1) {
          temp[*it]++;
          k++;
        }
      }
    }
    int x = 0;
    for (const auto& [key, values] : temp) {
      if (temp[key] == 1) {
        x++;
      }
    }
    if (x % 2 == 1) {
      x--;
    }
    k += x / 2;
    cout << k << "\n";
  }
}
