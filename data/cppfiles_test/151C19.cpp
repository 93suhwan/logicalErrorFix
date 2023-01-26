#include <bits/stdc++.h>
using namespace std;
void showlist(list<int> g) {
  list<int>::iterator it;
  for (it = g.begin(); it != g.end(); it++) {
    cout << *it << " ";
  }
  cout << '\n';
}
void solve() {
  long long n;
  cin >> n;
  map<int, list<int> > ar;
  int k = 0;
  int t;
  int x;
  int y;
  while (n--) {
    cin >> t;
    if (t == 1) {
      cin >> x;
      ar[x].push_back(k);
      k++;
    } else {
      cin >> x;
      cin >> y;
      if (x != y) {
        ar[y].splice(ar[y].begin(), ar[x]);
        ar[x] = {};
      }
    }
  }
  int aj[k];
  for (auto i : ar) {
    if (i.second.begin() != i.second.end()) {
      for (auto j : i.second) {
        aj[j] = i.first;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    cout << aj[i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
