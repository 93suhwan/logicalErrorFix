#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string arr[n];
  string ans[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int j = 0; j < m; j += 2) {
    map<int, vector<int>> nextChar;
    for (int i = 0; i < n; i++) {
      nextChar[(int)arr[i][j]].push_back((int)arr[i][j + 1]);
    }
    for (auto &it : nextChar) {
      sort(it.second.begin(), it.second.end(), greater<int>());
    }
    int index = 0;
    for (auto it : nextChar) {
      for (auto iter = it.second.begin(); iter != it.second.end(); iter++) {
        ans[index].push_back((char)it.first);
        ans[index].push_back((char)*iter);
        index++;
      }
    }
  }
  map<string, int> indices;
  for (int i = 0; i < n; i++) {
    indices[arr[i]] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    cout << indices[ans[i]] << " ";
  }
  cout << endl;
}
