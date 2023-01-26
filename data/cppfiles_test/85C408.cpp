#include <bits/stdc++.h>
using namespace std;
template <class T>
void printVec(vector<T> &vec) {
  cout << "vec: ----\n";
  for (int i = 0; i < vec.size(); ++i) cout << vec[i] << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  string str;
  while (t--) {
    cin >> str;
    int n = str.length() + 1;
    int res = 0;
    int q0 = 0;
    str += 'e';
    for (int i = 0; i < n; ++i) {
      if (str[i] == '0') {
        q0++;
        continue;
      } else {
        if (q0 > 0) res += 1;
        q0 = 0;
      }
    }
    if (res > 2)
      cout << 2 << '\n';
    else {
      cout << res << '\n';
    }
  }
}
