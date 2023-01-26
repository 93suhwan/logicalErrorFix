#include <bits/stdc++.h>
using namespace std;
void tick(int i, int j, int k, vector<vector<char>> &arr_cpy, int n, int m,
          vector<vector<char>> arr) {
  if (i + k >= n) return;
  vector<pair<int, int>> v;
  int curr_size = -1;
  int l = i, r = j;
  while (curr_size < k && l < n && r < m) {
    if (arr[l][r] == '*') {
      curr_size++;
      v.push_back(make_pair(l, r));
      l++;
      r++;
    } else
      return;
  }
  int curr_size2 = -1;
  l = i + k;
  r = j + k;
  while (curr_size2 < k && l >= 0 && r < m && l < n) {
    if (arr[i][j] == '*') {
      curr_size2++;
      v.push_back(make_pair(l, r));
      l--;
      r++;
    } else
      return;
  }
  if (curr_size == k && curr_size2 == k) {
    for (auto &it : v) {
      int a = it.first;
      int b = it.second;
      arr_cpy[a][b] = '.';
    }
  }
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> arr;
    for (int i = 0; i < n; i++) {
      vector<char> v1;
      for (int j = 0; j < m; j++) {
        char temp;
        cin >> temp;
        v1.push_back(temp);
      }
      arr.push_back(v1);
    }
    vector<vector<char>> arr_cpy = arr;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == '*')
          for (int random = k; random < n - i; random++) {
            tick(i, j, random, arr_cpy, n, m, arr);
          }
      }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr_cpy[i][j] == '*') {
          cout << "NO" << endl;
          flag = 1;
          break;
        }
      }
      if (flag == 1) break;
    }
    if (flag == 0) {
      { cout << "YES" << endl; }
    }
  }
}
