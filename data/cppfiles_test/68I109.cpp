#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, a, d;
  cin >> t;
  vector<long> sq;
  sq.push_back(1);
  int ptr = 1, pos;
  long square;
  for (int i = 0; i < t; i++) {
    cin >> a;
    if (a > ptr * ptr) {
      for (ptr = ptr + 1; ptr * ptr <= a; ptr++) sq.push_back(ptr * ptr);
      sq.push_back(ptr * ptr);
    }
    vector<long>::iterator it = lower_bound(sq.begin(), sq.end(), a);
    cout << *it << "\n";
    pos = it - sq.begin();
    square = (*it);
    int diff = square - a;
    if (diff <= pos)
      cout << pos << " " << diff << "\n";
    else
      cout << pos - (diff - pos) << " " << pos << "\n";
  }
  return 0;
}
