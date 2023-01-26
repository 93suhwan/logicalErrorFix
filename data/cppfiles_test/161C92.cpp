#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first < b.first || (a.first == b.first && a.second > b.second));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int> > range;
    for (int(i) = (0); i < (n); i++) {
      int l, r;
      cin >> l >> r;
      range.push_back(make_pair(l, r));
    }
    sort(range.begin(), range.end(), comp);
    for (int(i) = (0); i < (n - 1); i++) {
      cout << range[i].first << " " << range[i].second << " ";
      if (range[i + 1].first != range[i].first)
        cout << range[i].first;
      else
        cout << range[i + 1].second + 1;
      cout << "\n";
    }
    cout << range[n - 1].first << " " << range[n - 1].second << " "
         << range[n - 1].second << "\n";
  }
  return 0;
}
