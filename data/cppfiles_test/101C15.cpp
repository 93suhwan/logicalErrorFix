#include <bits/stdc++.h>
using namespace std;
bool comp(pair<char, int> a, pair<char, int> b) {
  if (a.first != b.first)
    return a.first < b.first;
  else
    return a.second < b.second;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC = 1;
  cin >> TC;
  while (TC--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    string st;
    cin >> st;
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; i++) {
      a[i].first = st[i];
      a[i].second = arr[i];
    }
    sort(a.begin(), a.end(), comp);
    int x = 1;
    bool flag = true;
    for (auto it : a) {
      if (it.second < x && it.first == 'R')
        ;
      else if (it.second > x && it.first == 'B')
        ;
      else if (it.second == x)
        ;
      else {
        flag = false;
        break;
      }
      x++;
    }
    if (flag)
      cout << "YES";
    else
      cout << "NO";
    if (TC) cout << '\n';
  }
  return 0;
}
