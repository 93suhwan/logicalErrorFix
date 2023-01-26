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
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> V(n);
  cin >> V;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int ile = 0;
      int gx = j, gx2 = j;
      int gy = i;
      while (gy >= 0 && gx >= 0 && gx2 < m) {
        if (V[gy][gx] == '.' || V[gy][gx2] == '.') break;
        ile++;
        gy--;
        gx--;
        gx2++;
      }
      if (ile > k) {
        gx = j;
        gx2 = j;
        gy = i;
        while (ile > 0) {
          V[gy][gx] = '#';
          V[gy][gx2] = '#';
          ile--;
          gy--;
          gx--;
          gx2++;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (V[i][j] == '*') {
        cout << "NO" << (char)10;
        return;
      }
  cout << "YES" << (char)10;
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
