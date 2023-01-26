#include <bits/stdc++.h>
using namespace std;
void solution() {
  set<vector<int>> result;
  set<int> array;
  int value;
  int c = 0;
  int val;
  cin >> value;
  for (int i = 0; i < value; ++i) {
    cin >> val;
    array.insert(val);
  }
  for (auto i : array) {
    if (i != *array.begin()) {
      cout << i << " " << *array.begin() << endl;
      c++;
    }
    if (c >= value / 2) {
      break;
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    solution();
  }
}
