#include <bits/stdc++.h>
using namespace std;
long long int temp[100002];
long long int solve(int num_enemies) {
  long long int cur_min_power = temp[1] + 1;
  long long int net_level_inc = 1;
  int cur_index = 1;
  while (cur_index < num_enemies) {
    if (temp[cur_index + 1] >= cur_min_power + net_level_inc) {
      cur_min_power = temp[cur_index + 1] - net_level_inc + 1;
      net_level_inc++;
      cur_index++;
    } else {
      net_level_inc++;
      cur_index++;
    }
  }
  return cur_min_power;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int num_enemies[100002];
    long long int min_power[100002];
    for (int i = 1; i <= n; i++) {
      cin >> num_enemies[i];
      for (int j = 1; j <= num_enemies[i]; j++) {
        cin >> temp[j];
      }
      min_power[i] = solve(num_enemies[i]);
    }
    sort(min_power + 1, min_power + n + 1);
    long long int cur_min_power = min_power[1];
    int cur_index = 1;
    long long int net_level_inc = num_enemies[1];
    while (cur_index <= n) {
      if (min_power[cur_index + 1] <= cur_min_power + net_level_inc) {
        net_level_inc += num_enemies[cur_index + 1];
        cur_index++;
      } else {
        cur_min_power = min_power[cur_index + 1] - net_level_inc;
        net_level_inc += num_enemies[cur_index + 1];
        cur_index++;
      }
    }
    cout << cur_min_power << endl;
  }
  return 0;
}
