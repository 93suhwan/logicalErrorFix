#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    unordered_map<char, int> umap;
    for (char c : s) umap[c]++;
    int even_sum = 0, res = 0;
    for (auto i : umap) {
      if (i.second == 1) {
        even_sum++;
      } else {
        res++;
      }
    }
    res += (even_sum / 2);
    cout << res << '\n';
  }
  return 0;
}
