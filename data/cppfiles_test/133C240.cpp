#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  char f, j;
  pair<char, char> p;
  cin >> n;
  vector<pair<char, char> > bg;
  for (int i = 0; i < n - 2; i++) {
    cin >> p.first >> p.second;
    bg.push_back(p);
  }
  bool flag = false;
  cout << bg[0].first;
  for (int i = 0; i < n - 3; i++) {
    if (bg[i].second == bg[i + 1].first) {
      cout << bg[i].second;
    } else {
      flag = true;
      cout << bg[i].second << bg[i + 1].first;
    }
  }
  if (flag == false) {
    cout << bg[n - 3].second << bg[n - 3].second;
  } else {
    cout << bg[n - 3].second;
  }
  printf("\n");
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
