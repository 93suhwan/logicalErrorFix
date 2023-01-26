#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  vector<pair<string, int> > A(x);
  for (int i = 0; i < x; i++) {
    string r;
    cin >> r;
    for (int j = 1; j < r.size(); j += 2) r[j] = 'Z' - (r[j] - 'A');
    A[i] = make_pair(r, i + 1);
  }
  for (int i = 0; i < x; i++) cout << A[i].second << (i + 1 == x ? "\n" : " ");
  return 0;
}
