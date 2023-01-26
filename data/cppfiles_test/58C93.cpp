#include <bits/stdc++.h>
using namespace std;
int dy[] = {1, 1, 1};
int dx[] = {1, 0, -1};
void traverse(int x, int y, vector<vector<int> > &ans, int n, bool &flag) {
  if (flag == true) return;
  if (x == 1 and y == n - 1) {
    flag = true;
    return;
  }
  for (int k = 0; k < 3; k++) {
    if (!flag and x + dx[k] >= 0 and x + dx[k] <= 1 and y + dy[k] >= 0 and
        y + dy[k] <= n - 1 and ans[x + dx[k]][y + dy[k]] == 0) {
      return (traverse(x + dx[k], y + dy[k], ans, n, flag));
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int> > ans(2, vector<int>(n, 0));
    string stub;
    for (int i = 0; i < 2; i++) {
      string temp;
      cin >> temp;
      stub += temp;
    }
    int start = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        ans[i][j] = stub[start] - '0';
        start++;
      }
    }
    bool flag = false;
    traverse(0, 0, ans, n, flag);
    if (flag)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}
