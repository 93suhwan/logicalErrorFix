#include <bits/stdc++.h>
using namespace std;
bool isRight(const string &a) {
  string st;
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] == '(') {
      st += a[(int)a.size() - 1];
    } else {
      if ((int)st.size() != 0) {
        st.pop_back();
      } else
        return false;
    }
  }
  return (int)st.size() == 0;
}
vector<string> strs;
void skobki(int n, string a) {
  if ((int)a.size() >= 2 * n) {
    if (isRight(a)) {
      strs.push_back(a);
    }
    return;
  }
  skobki(n, a + ')');
  skobki(n, a + '(');
}
map<int, int> start;
void solve() {
  int n;
  cin >> n;
  cout << "/////////" << endl;
  skobki(n, "(");
  for (int i = ((int)strs.size() - start[n] < n
                    ? start[n] - (n - ((int)strs.size() - start[n]))
                    : start[n]),
           j = 0;
       i < (int)strs.size() and j < n; ++i, ++j) {
    start[n] = start[n] + 1;
    cout << strs[i] << endl;
  }
  strs.clear();
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
