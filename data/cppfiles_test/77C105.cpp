#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> res;
string convBit(int a) {
  string ret(4, '0');
  for (int i = 0; i < 4; i++) {
    if ((a >> i) & 1) ret[3 - i] = '1';
  }
  return ret;
}
int util(int i, int j, vector<vector<int> > &rooms) {
  string s = convBit(rooms[i][j]);
  int ret = 1;
  rooms[i][j] = -1;
  if (s[0] == '0' && i - 1 >= 0 && rooms[i - 1][j] != -1)
    ret += util(i - 1, j, rooms);
  if (s[1] == '0' && j + 1 < m && rooms[i][j + 1] != -1)
    ret += util(i, j + 1, rooms);
  if (s[2] == '0' && i + 1 < n && rooms[i + 1][j] != -1)
    ret += util(i + 1, j, rooms);
  if (s[3] == '0' && j - 1 >= 0 && rooms[i][j - 1] != -1)
    ret += util(i, j - 1, rooms);
  return ret;
}
int main() {
  cin >> n >> m;
  vector<vector<int> > rooms(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> rooms[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (rooms[i][j] != -1) res.push_back(util(i, j, rooms));
    }
  }
  sort(res.begin(), res.end(), greater<int>());
  for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
  cout << endl;
}
