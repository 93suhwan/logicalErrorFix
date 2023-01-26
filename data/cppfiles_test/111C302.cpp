#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct cmp {
  bool operator()(const T &p1, const T &p2) {}
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cout << "()";
    cout << endl;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          cout << "(())", j++;
        else
          cout << "()";
      }
      cout << endl;
    }
  }
  return 0;
}
