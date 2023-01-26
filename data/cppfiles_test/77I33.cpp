#include <bits/stdc++.h>
using namespace std;
string decimalToBinary(int n) {
  string s = bitset<4>(n).to_string();
  return s;
}
int ar[2000][2000];
int vis[2000][2000];
int co = 0;
void make(int i, int j, int n, int m) {
  if (vis[i][j] == 1) {
    return;
  }
  vis[i][j] = 1;
  co += 1;
  if (i - 1 >= 0) {
    string s1 = decimalToBinary(ar[i][j]);
    string s2 = decimalToBinary(ar[i - 1][j]);
    if (s1[0] == '0' && s2[2] == '0') {
      make(i - 1, j, n, m);
    }
  }
  if (j - 1 >= 0) {
    string s1 = decimalToBinary(ar[i][j]);
    string s2 = decimalToBinary(ar[i][j - 1]);
    if (s1[3] == '0' && s2[1] == '0') {
      make(i, j - 1, n, m);
    }
  }
  if (i + 1 < n) {
    string s1 = decimalToBinary(ar[i][j]);
    string s2 = decimalToBinary(ar[i + 1][j]);
    if (s1[2] == '0' && s2[0] == '0') {
      make(i + 1, j, n, m);
    }
  }
  if (j + 1 < m) {
    string s1 = decimalToBinary(ar[i][j]);
    string s2 = decimalToBinary(ar[i][j + 1]);
    if (s1[1] == '0' && s2[3] == '0') {
      make(i, j + 1, n, m);
    }
  }
}
void f() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ar[i][j];
      vis[i][j] = 0;
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] == 0) {
        co = 0;
        make(i, j, n, m);
        ans.push_back(co);
      }
    }
  }
  sort(ans.rbegin(), ans.rend());
  for (auto x : ans) {
    cout << x << " ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    f();
  }
}
