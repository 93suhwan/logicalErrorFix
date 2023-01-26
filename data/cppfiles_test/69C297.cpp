#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<string> powers;
  for (long long i = 1; i <= 2e18; i *= 2) {
    powers.push_back(to_string(i));
  }
  while (t--) {
    string num;
    cin >> num;
    int size = num.size();
    int minimum = 1e5;
    for (int i = 0; i < powers.size(); i++) {
      string temp = num;
      int cnt = 0;
      for (long long j = 0; j < temp.size(); j++) {
        if (temp[j] != powers[i][j]) {
          temp.erase(temp.begin() + j);
          j--;
        } else {
          cnt++;
        }
      }
      int res = size - cnt + powers[i].size() - cnt;
      minimum = min(minimum, res);
    }
    cout << minimum << endl;
  }
  return 0;
}
