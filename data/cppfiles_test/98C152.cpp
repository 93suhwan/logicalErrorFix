#include <bits/stdc++.h>
using namespace std;
const int MS = 1000001;
const long long int INF = 1e9 + 7;
template <class T>
bool comp(T a, T b) {
  if (a < b) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = -1, r = -1;
    for (int i = 0; i < s.size(); i++) {
      int cnta = 0, cntb = 0;
      for (int j = i; j < s.size(); j++) {
        if (s[j] == 'a')
          cnta++;
        else
          cntb++;
        if (cnta == cntb && cnta && cntb) l = i + 1, r = j + 1;
      }
    }
    cout << l << " " << r << "\n";
  }
}
