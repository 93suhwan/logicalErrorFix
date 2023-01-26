#include <bits/stdc++.h>
using namespace std;
int hor[2][200005];
int ver[2][200005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int w, h;
    cin >> w >> h;
    int h1, h2, v1, v2;
    cin >> h1;
    for (int i = 0; i < h1; i++) {
      cin >> hor[0][i];
    }
    cin >> h2;
    for (int i = 0; i < h2; i++) {
      cin >> hor[1][i];
    }
    cin >> v1;
    for (int i = 0; i < v1; i++) {
      cin >> ver[0][i];
    }
    cin >> v2;
    for (int i = 0; i < v2; i++) {
      cin >> ver[1][i];
    }
    int vl1 = ver[0][v1 - 1] - ver[0][0];
    int hh1 = max(hor[1][h2 - 1], hor[0][h1 - 1]);
    int vl2 = ver[1][v2 - 1] - ver[1][0];
    int hh2 = max(w - hor[0][0], w - hor[1][0]);
    int hl1 = hor[0][h1 - 1] - hor[0][0];
    int vh1 = max(ver[1][v2 - 1], ver[0][v1 - 1]);
    int hl2 = hor[1][h2 - 1] - hor[1][0];
    int vh2 = max(h - ver[0][0], h - ver[1][0]);
    int ans = max({vl1 * w, vl2 * w, hl1 * h, hl2 * h});
    cout << ans << '\n';
  }
}
