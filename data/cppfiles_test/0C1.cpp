#include <bits/stdc++.h>
using namespace std;
using Item = pair<string, int>;
struct ItemComparator {
  inline bool operator()(const Item& lhs, const Item& rhs) {
    int pos{0};
    while (lhs.first[pos] == rhs.first[pos]) ++pos;
    return pos & 1 ? lhs.first[pos] > rhs.first[pos]
                   : lhs.first[pos] < rhs.first[pos];
  }
};
int main() {
  int n, m;
  string s;
  vector<Item> items;
  cin >> n >> m;
  items.reserve(n);
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    items.push_back(make_pair(s, i));
  }
  sort(items.begin(), items.end(), ItemComparator());
  for (int i = 0; i < n; ++i) {
    cout << items[i].second << " ";
  }
  cout << "\n";
  return 0;
}
