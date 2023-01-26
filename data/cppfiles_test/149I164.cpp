#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ull n, k, x;
    cin >> n >> k >> x;
    cin.ignore();
    string arr;
    getline(cin, arr);
    vector<pair<ull, ull>> values;
    for (int i = arr.size(); i-- > 0;) {
      if (arr[i] == 'a') {
        if (i == arr.size() - 1 || arr[i + 1] != 'a')
          values.emplace_back(0, 1);
        else
          values.back().second++;
        continue;
      }
      if (i == arr.size() - 1)
        values.emplace_back(1, k);
      else if (arr[i + 1] == '*')
        values.back().second += k;
      else {
        pair<ull, ull> lastValue = {1, 0};
        for (int j = values.size(); j-- > 0;) {
          if (values[j].first == 0) continue;
          lastValue = values[j];
          break;
        }
        values.emplace_back((lastValue.second + 1) * lastValue.first, k);
      }
    }
    x--;
    for (int i = values.size(); i-- > 0;) {
      if (values[i].first == 0) {
        for (int j = 0; j < values[i].second; j++) cout << 'a';
        continue;
      }
      int total_b = x / values[i].first;
      for (int j = 0; j < total_b; j++) cout << 'b';
      x -= total_b * values[i].first;
    }
    cout << endl;
  }
}
