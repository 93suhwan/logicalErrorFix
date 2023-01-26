#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int tt = 0; tt < t; ++tt) {
    int n, m;
    cin >> n >> m;
    getchar();
    char ch = getchar();
    int xmin = 0, xmax = 0, ymin = 0, ymax = 0;
    int curx = 0, cury = 0;
    bool going = true;
    while (ch != '\n') {
      if (going) {
        int _xmin = xmin, _xmax = xmax, _ymin = ymin, _ymax = ymax;
        int _curx = curx, _cury = cury;
        switch (ch) {
          case 'L':
            --_curx;
            break;
          case 'R':
            ++_curx;
            break;
          case 'U':
            --_cury;
            break;
          case 'D':
            ++_cury;
            break;
        }
        if (_curx < _xmin) _xmin = _curx;
        if (_curx > _xmax) _xmax = _curx;
        if (_cury < _ymin) _ymin = _cury;
        if (_cury > _ymax) _ymax = _cury;
        if (_xmax - _xmin >= m || _ymax - _ymin >= n)
          going = false;
        else {
          xmin = _xmin;
          xmax = _xmax;
          ymin = _ymin;
          ymax = _ymax;
          curx = _curx;
          cury = _cury;
        }
      }
      ch = getchar();
    }
    cout << -ymin + 1 << ' ' << -xmin + 1 << '\n';
  }
  return 0;
}
