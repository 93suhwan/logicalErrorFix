#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int tst, i, sz;
  cin >> tst;
  vector<char> v1;
  while (tst--) {
    cin >> str;
    sz = str.size();
    sort(str.begin(), str.end());
    i = 0;
    while (i < sz) {
      vector<char>::iterator pos1, pos2;
      pos2 = upper_bound(v1.begin(), v1.end(), str[i]);
      pos1 = lower_bound(v1.begin(), v1.end(), str[i]);
      (pos1 + 1 == pos2) ? (v1.push_back(str[i]), i++)
      : (pos1 == pos2)   ? (v1.push_back(str[i]), i++)
                         : i++;
    }
    cout << v1.size() / 2 << endl;
    v1.clear();
  }
}
