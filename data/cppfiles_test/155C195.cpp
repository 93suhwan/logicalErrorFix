#include <bits/stdc++.h>
using namespace std;
struct XX {
  int x;
  int xx;
  int f;
  int i;
};
class xxGreater {
 public:
  bool operator()(const XX& riLeft, const XX& riRight) const {
    return (riLeft.x) < (riRight.x);
  }
};
class xxGreater2 {
 public:
  bool operator()(const XX& riLeft, const XX& riRight) const {
    return (riLeft.i) < (riRight.i);
  }
};
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int a[200000];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    XX x[200000];
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        x[i].x = a[i];
        x[i].i = i;
        x[i].f = 1;
      } else {
        x[i].x = a[i];
        x[i].i = i;
        x[i].f = 0;
      }
    }
    sort(x, x + n, xxGreater());
    int ind = 1;
    for (int i = 0; i < n; i++) {
      if (x[i].f == 0) {
        x[i].xx = ind;
        ind++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (x[i].f == 1) {
        x[i].xx = ind;
        ind++;
      }
    }
    sort(x, x + n, xxGreater2());
    for (int i = 0; i < n; i++) {
      cout << x[i].xx << " ";
    }
    cout << endl;
  }
  return 0;
}
