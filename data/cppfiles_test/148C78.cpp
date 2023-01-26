#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int w, h;
    cin >> w >> h;
    long long int h1, h2;
    cin >> h1;
    long long int x1[h1];
    for (int i = 0; i < h1; i++) cin >> x1[i];
    long long int s1 = x1[h1 - 1] - x1[0];
    cin >> h2;
    long long int x2[h2];
    for (int i = 0; i < h2; i++) cin >> x2[i];
    long long int s2 = x2[h2 - 1] - x2[0];
    long long int a1 = h * max(s1, s2);
    long long int v1, v2;
    cin >> v1;
    long long int y1[v1];
    for (int i = 0; i < v1; i++) cin >> y1[i];
    long long int s3 = y1[v1 - 1] - y1[0];
    cin >> v2;
    long long int y2[v2];
    for (int i = 0; i < v2; i++) cin >> y2[i];
    long long int s4 = y2[v2 - 1] - y2[0];
    long long int a2 = w * max(s3, s4);
    cout << max(a1, a2) << endl;
  }
}
