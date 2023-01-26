#include <bits/stdc++.h>
using namespace std;
void solution1(int a, int b, map<pair<int, int>, bool>& mp1,
               map<pair<int, int>, int>& mp2) {
  if (a == b) {
    mp2[{a, b}] = a;
    return;
  }
  int j = a;
  while (j <= b) {
    if (j == a) {
      if (mp1[{j + 1, b}]) {
        mp2[{a, b}] = j;
        solution1(j + 1, b, mp1, mp2);
        break;
      }
    } else if (j == b) {
      if (mp1[{a, j - 1}]) {
        mp2[{a, b}] = j;
        solution1(a, j - 1, mp1, mp2);
        break;
      }
    } else {
      if (mp1[{a, j - 1}] && mp1[{j + 1, b}]) {
        mp2[{a, b}] = j;
        solution1(a, j - 1, mp1, mp2);
        solution1(j + 1, b, mp1, mp2);
        break;
      }
    }
    j++;
  }
}
void solve() {
  int a;
  cin >> a;
  map<pair<int, int>, bool> mp1;
  map<pair<int, int>, int> mp2;
  int x, y;
  for (int i = 0; i < a; i++) {
    cin >> x >> y;
    mp1[{x, y}] = 1;
  }
  solution1(1, a, mp1, mp2);
  vector<vector<int>> v1;
  int i = 0;
  for (auto x : mp1) {
    if (mp2[x.first]) {
      cout << x.first.first << " " << x.first.second << " " << mp2[x.first]
           << endl;
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  int a;
  cin >> a;
  while (a--) {
    solve();
    cout << endl;
  }
  return 0;
}
