#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int num_enemies;
    long long int min_power;
    vector<pair<int, long long int>> arr;
    for (int i = 0; i < n; i++) {
      cin >> num_enemies;
      min_power = -1;
      for (int j = 0; j < num_enemies; j++) {
        long long int temp;
        cin >> temp;
        min_power = max(min_power, temp + 1 - j);
      }
      arr.push_back(make_pair(min_power, num_enemies));
    }
    sort(arr.begin(), arr.end());
    long long int cur_min_power = arr[0].first;
    int cur_index = 0;
    long long int net_level_inc = arr[0].second;
    while (cur_index < n - 1) {
      if (arr[cur_index + 1].first <= cur_min_power + net_level_inc) {
        net_level_inc += arr[cur_index + 1].second;
        cur_index++;
      } else {
        cur_min_power = arr[cur_index + 1].first - net_level_inc;
        net_level_inc += arr[cur_index + 1].second;
        cur_index++;
      }
    }
    cout << cur_min_power << endl;
  }
  return 0;
}
