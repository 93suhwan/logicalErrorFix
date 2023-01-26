#include <bits/stdc++.h>
using namespace std;
string bin(int x) {
  if (x == 0)
    return "0000";
  else if (x == 1)
    return "0001";
  else if (x == 2)
    return "0010";
  else if (x == 3)
    return "0011";
  else if (x == 4)
    return "0100";
  else if (x == 5)
    return "0101";
  else if (x == 6)
    return "0110";
  else if (x == 7)
    return "0111";
  else if (x == 8)
    return "1000";
  else if (x == 9)
    return "1001";
  else if (x == 10)
    return "1010";
  else if (x == 11)
    return "1011";
  else if (x == 12)
    return "1100";
  else if (x == 13)
    return "1101";
  else if (x == 14)
    return "1110";
  return "1111";
}
string arr[1003][1003];
int cnt = 0;
int n, m;
bool vis[1003][1003];
void dfs(int i, int j) {
  cnt++;
  vis[i][j] = true;
  if (i - 1 > 0) {
    if (arr[i][j][0] == '0' && arr[i - 1][j][2] == '0' &&
        vis[i - 1][j] == false)
      dfs(i - 1, j);
  }
  if (i + 1 <= n) {
    if (arr[i][j][2] == '0' && arr[i + 1][j][0] == '0' &&
        vis[i + 1][j] == false)
      dfs(i + 1, j);
  }
  if (j + 1 <= m) {
    if (arr[i][j][1] == '0' && arr[i][j + 1][3] == '0' &&
        vis[i][j + 1] == false)
      dfs(i, j + 1);
  }
  if (j - 1 > 0) {
    if (arr[i][j][3] == '0' && arr[i][j - 1][1] == '0' &&
        vis[i][j - 1] == false)
      dfs(i, j - 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      string ss = bin(x);
      arr[i][j] = ss;
    }
  }
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i][j] == false) {
        cnt = 0;
        dfs(i, j);
        vec.push_back(cnt);
      }
    }
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << '\n';
  return 0;
}
