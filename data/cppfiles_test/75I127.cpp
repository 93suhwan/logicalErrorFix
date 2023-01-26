#include <bits/stdc++.h>
using namespace std;
void solve() {
  int cave;
  cin >> cave;
  int power, size;
  vector<vector<int>> arr(cave, vector<int>());
  for (int i = 0; i < cave; i++) {
    cin >> size;
    for (int j = 0; j < size; j++) {
      cin >> power;
      arr[i].push_back(power);
    }
  }
  int minPower1 = arr[arr.size() - 1][0] + 1;
  int increment = 0;
  for (int i = arr.size() - 1; i >= 0; i--) {
    for (int j = 0; j < arr[i].size(); j++) {
      if (minPower1 + increment <= arr[i][j])
        minPower1 = arr[i][j] - increment + 1;
      increment++;
    }
  }
  int minPower2 = arr[0][0] + 1;
  increment = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      if (minPower2 + increment <= arr[i][j])
        minPower2 = arr[i][j] - increment + 1;
      increment++;
    }
  }
  cout << min(minPower1, minPower2) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
