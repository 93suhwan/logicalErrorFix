#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b) { return a > b; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
      int first;
      cin >> first;
      freq[first]++;
    }
    auto it = freq.begin();
    bool ok = 1;
    long long prev = 0;
    multiset<int> free_nos;
    for (int i = 0; i <= n; ++i) {
      if (!ok) {
        cout << "-1 ";
      } else if (it != freq.end() && it->first == i) {
        cout << prev + it->second << " ";
        for (int _ = 1; _ < it->second; ++_) free_nos.insert(it->first);
        it++;
      } else if (it == freq.end() || it->first > i) {
        cout << prev << " ";
        if (free_nos.empty()) {
          ok = 0;
        } else {
          prev += i - (*free_nos.rbegin());
          free_nos.erase(free_nos.find(*free_nos.rbegin()));
        }
      }
    }
    cout << '\n';
  }
}
