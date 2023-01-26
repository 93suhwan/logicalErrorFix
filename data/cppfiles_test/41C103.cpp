#include <bits/stdc++.h>
using namespace std;
int colour[1010][1010], n, k, mx;
int group[1010];
void solve(vector<int> &v, int c) {
  if (v.size() <= 1) return;
  mx = max(mx, c);
  vector<vector<int> > groups;
  for (int i = 0; i < k; i++) {
    groups.push_back(vector<int>());
  }
  int amPerGroup = ((int)v.size() + k - 1) / k;
  int currGroup = 0;
  int numInGroup = 0;
  for (auto a : v) {
    groups[currGroup].push_back(a);
    group[a] = currGroup;
    numInGroup++;
    if (numInGroup == amPerGroup) {
      numInGroup = 0;
      currGroup++;
    }
  }
  for (auto a : v) {
    for (auto b : v) {
      if (group[a] != group[b]) {
        colour[a][b] = c;
      }
    }
  }
  for (auto &v2 : groups) {
    solve(v2, c + 1);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  vector<int> v;
  for (int i = 0; i < n; i++) v.push_back(i);
  solve(v, 1);
  printf("%d\n", mx);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      printf("%d ", colour[i][j]);
    }
  }
  printf("\n");
}
