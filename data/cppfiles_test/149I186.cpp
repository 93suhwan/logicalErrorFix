#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, k, x;
    cin >> n >> k >> x;
    cin.ignore();
    string arr;
    getline(cin, arr);
    vector<pair<ll, ll>> values;
    for (int i = arr.size(); i-- > 0;) {
      if (arr[i] == 'a') {
        if (i == arr.size() - 1 || arr[i + 1] != 'a')
          values.emplace_back(-1, 1);
        else
          values.back().second++;
        continue;
      }
      if (i == arr.size() - 1)
        values.emplace_back(1, k);
      else if (arr[i + 1] == '*')
        values.back().second += k;
      else {
        pair<ll, ll> lastValue = {1, 0};
        for (int j = values.size(); j-- > 0;) {
          if (values[j].first == -1) continue;
          lastValue = values[j];
          break;
        }
        values.emplace_back((lastValue.second + 1) * lastValue.first, 1);
      }
    }
    string res = "";
    x--;
    for (int i = values.size(); i-- > 0;) {
      if (values[i].first == -1) {
        for (int j = 0; j < values[i].second; j++) res += 'a';
        continue;
      }
      int total_b = x / values[i].first;
      for (int j = 0; j < total_b; j++) res += 'b';
      x -= total_b * values[i].first;
    }
    cout << res << endl;
  }
}
