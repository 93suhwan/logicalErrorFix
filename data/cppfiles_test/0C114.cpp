#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> arr;
  for (int i = 0; i < n; i++) {
    string val;
    cin >> val;
    arr.push_back(val);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j += 2) {
      arr[i][j] = (char)(90 - (int)arr[i][j] + 65);
    }
  }
  map<string, int> indices;
  for (int i = 0; i < n; i++) {
    indices[arr[i]] = i + 1;
  }
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++) {
    cout << indices[arr[i]] << " ";
  }
  cout << endl;
}
