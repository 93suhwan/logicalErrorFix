#include <bits/stdc++.h>
using namespace std;
void check(vector<vector<int>> &race, int n) {
  int max = 0;
  int pos = -1;
  for (int i = 1; i < n; i++) {
    int flag = 0;
    for (int j = 0; j < 5; j++) {
      if (race[i][j] < race[max][j]) flag++;
    }
    if (flag >= 3) {
      max = i;
    }
  }
  int i;
  for (i = 0; i < n; i++) {
    int flag = 0;
    for (int j = 0; j < 5; j++) {
      if (i != j) {
        if (race[i][j] < race[max][j]) {
          flag++;
        }
      }
    }
    if (flag >= 3) {
      cout << -1 << "\n";
      return;
    }
  }
  cout << max + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t) {
    int n;
    cin >> n;
    vector<vector<int>> race(n, vector<int>(5, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; ++j) {
        int a;
        cin >> a;
        race[i][j] = a;
      }
    }
    check(race, n);
    t--;
  }
  return 0;
}
