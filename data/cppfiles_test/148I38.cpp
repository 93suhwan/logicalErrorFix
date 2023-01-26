#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int w, h;
    cin >> w >> h;
    int h1, h2;
    cin >> h1;
    int x1[h1];
    for (int i = 0; i < h1; i++) cin >> x1[i];
    int s1 = x1[h1 - 1] - x1[0];
    cin >> h2;
    int x2[h2];
    for (int i = 0; i < h2; i++) cin >> x2[i];
    int s2 = x2[h2 - 1] - x2[0];
    int a1 = h * max(s1, s2);
    int v1, v2;
    cin >> v1;
    int y1[v1];
    for (int i = 0; i < v1; i++) cin >> y1[i];
    int s3 = y1[v1 - 1] - y1[0];
    cin >> v2;
    int y2[v2];
    for (int i = 0; i < v2; i++) cin >> y2[i];
    int s4 = y2[v2 - 1] - y2[0];
    int a2 = w * max(s3, s4);
    cout << max(a1, a2) << endl;
  }
}
