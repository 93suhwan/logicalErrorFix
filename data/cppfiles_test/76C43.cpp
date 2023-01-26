#include <bits/stdc++.h>
using namespace std;
vector<int> sus(5);
bool found = false;
bool used[49];
bool edge[49][49];
int n, m;
void solve() {
  if (found) return;
  found = true;
  for (int i = 0; i < 5; i++) cout << sus[i] << " ";
}
void bt1(int x) {
  if (found) return;
  if (x == 5)
    solve();
  else {
    for (int i = 1; i <= min(n, 48); i++) {
      if (!used[i]) {
        bool good = true;
        for (int j = 0; j < x; j++)
          if (!edge[i][sus[j]]) good = false;
        if (good) {
          used[i] = true;
          sus[x] = i;
          bt1(x + 1);
          used[i] = false;
        }
      }
    }
  }
}
void bt2(int x) {
  if (found) return;
  if (x == 5)
    solve();
  else {
    for (int i = 1; i <= min(n, 48); i++) {
      if (!used[i]) {
        bool good = true;
        for (int j = 0; j < x; j++)
          if (edge[i][sus[j]]) good = false;
        if (good) {
          used[i] = true;
          sus[x] = i;
          bt2(x + 1);
          used[i] = false;
        }
      }
    }
  }
}
int main() {
  memset(used, false, sizeof(used));
  memset(edge, false, sizeof(edge));
  for (int i = 0; i < 49; i++) {
    edge[i][i] = true;
  }
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a <= 48 && b <= 48) {
      edge[a][b] = true;
      edge[b][a] = true;
    }
  }
  bt1(0);
  if (!found) bt2(0);
  if (!found) cout << -1;
}
