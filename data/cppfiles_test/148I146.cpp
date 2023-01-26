#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, d, w, h;
    cin >> w >> h;
    int h1, h2, v1, v2, d1, d2, d3, d4;
    double k, v;
    cin >> h1;
    vector<int> ha(h1);
    for (i = 0; i < h1; i++) {
      cin >> ha[i];
    }
    d1 = ha[h1 - 1] - ha[0];
    cin >> h2;
    vector<int> hb(h2);
    for (i = 0; i < h2; i++) {
      cin >> hb[i];
    }
    d2 = hb[h2 - 1] - hb[0];
    cin >> v1;
    vector<int> va(v1);
    for (i = 0; i < v1; i++) {
      cin >> va[i];
    }
    d3 = va[v1 - 1] - va[0];
    cin >> v2;
    vector<int> vb(v2);
    for (i = 0; i < v2; i++) {
      cin >> vb[i];
    }
    d4 = vb[v2 - 1] - vb[0];
    k = max(0.5 * d1 * h, 0.5 * d2 * h);
    v = max(0.5 * d3 * w, 0.5 * d4 * w);
    v = max(k, v);
    cout << v * 2 << endl;
  }
}
