#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    set<vector<int>> result;
    set<int> array;
    int value;
    cin >> value;
    int val;
    for (int i = 0; i < value; i++) {
      cin >> val;
      array.insert(val);
    }
    for (auto i : array) {
      if (i != *array.begin()) {
        cout << i << " " << *array.begin() << endl;
        value++;
      }
      if (value >= value / 2) {
        break;
      }
    }
  }
}
