#include <bits/stdc++.h>
using namespace std;
bool comp(vector<int> v1, vector<int> v2) {
  return *max_element(v1.begin(), v1.end()) <
         *max_element(v2.begin(), v2.end());
}
void solve() {
  int cave;
  cin >> cave;
  int power, size;
  vector<vector<int>> arr(cave, vector<int>());
  map<int, int> mp;
  for (int i = 0; i < cave; i++) {
    cin >> size;
    for (int j = 0; j < size; j++) {
      cin >> power;
      arr[i].push_back(power);
    }
  }
  sort(arr.begin(), arr.end(), comp);
  int minPower = arr[0][0] + 1;
  int increment = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      if (minPower + increment <= arr[i][j])
        minPower = arr[i][j] - increment + 1;
      increment++;
    }
  }
  cout << minPower << "\n";
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
