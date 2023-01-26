#include <bits/stdc++.h>
using namespace std;
int parent[1005], parent2[1005];
void join(int a, int b) {
  while (parent[a] > 0) {
    a = parent[a];
  }
  while (parent[b] > 0) {
    b = parent[b];
  }
  if (abs(parent[a]) > abs(parent[b])) {
    parent[a] += parent[b];
    parent[b] = a;
  } else {
    parent[b] += parent[a];
    parent[a] = b;
  }
}
bool check(int a, int b) {
  while (parent[a] > 0) {
    a = parent[a];
  }
  while (parent[b] > 0) {
    b = parent[b];
  }
  if (a == b) {
    return false;
  }
  return true;
}
void join2(int a, int b) {
  while (parent2[a] > 0) {
    a = parent2[a];
  }
  while (parent2[b] > 0) {
    b = parent2[b];
  }
  if (abs(parent2[a]) > abs(parent2[b])) {
    parent2[a] += parent2[b];
    parent2[b] = a;
  } else {
    parent2[b] += parent2[a];
    parent2[a] = b;
  }
}
bool check2(int a, int b) {
  while (parent2[a] > 0) {
    a = parent2[a];
  }
  while (parent2[b] > 0) {
    b = parent2[b];
  }
  if (a == b) {
    return false;
  }
  return true;
}
int main() {
  memset(parent, -1, sizeof(parent));
  memset(parent2, -1, sizeof(parent2));
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    int x, y;
    cin >> x >> y;
    join(x, y);
  }
  for (int i = 0; i < b; i++) {
    int x, y;
    cin >> x >> y;
    join2(x, y);
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (check(i, j) && check2(i, j)) {
        ans.push_back({i, j});
        join(i, j);
        join2(i, j);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it.first << " " << it.second << endl;
  }
}
