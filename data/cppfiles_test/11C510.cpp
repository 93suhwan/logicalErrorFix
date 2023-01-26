#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (int i = 0; i < vec.size(); ++i) is >> vec[i];
  return is;
}
template <class T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  for (auto& t : vec) os << t << " ";
  return os;
}
void st() {
  int n;
  cin >> n;
  vector<string> V(n);
  cin >> V;
  vector<vector<int> > C(n, vector<int>(5, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < V[i].size(); ++j) {
      C[i][V[i][j] - 'a']++;
    }
  }
  vector<int> ord(n);
  for (int i = 0; i < n; ++i) ord[i] = i;
  int ans = 0;
  for (int l = 0; l < 5; ++l) {
    sort((ord).begin(), (ord).end(), [&C, &V, l](int a, int b) {
      return 2 * C[a][l] - (int)V[a].size() > 2 * C[b][l] - (int)V[b].size();
    });
    int delta = 0;
    for (int i = 0; i < n; ++i) {
      delta += 2 * C[ord[i]][l] - (int)V[ord[i]].size();
      if (delta > 0) ans = max(ans, i + 1);
    }
  }
  cout << ans << (char)10;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    if (t < 50) {
      cerr << "-------------------" << (char)10;
    }
    st();
  }
}
