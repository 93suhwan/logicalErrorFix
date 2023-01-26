#include <bits/stdc++.h>
using namespace std;
void fastInput() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fastInput();
  vector<int> v[500005];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      v[x].push_back(i);
    } else {
      int x, y;
      cin >> x >> y;
      if (x != y) {
        if (v[x].size() > v[y].size()) swap(v[x], v[y]);
        for (int j = 0; j < v[x].size(); j++) v[y].push_back(v[x][j]);
        v[x].clear();
      }
      n--;
      i--;
    }
  }
  int arr[500005];
  for (int i = 0; i < 1e5 + 1; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      arr[v[i][j]] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
