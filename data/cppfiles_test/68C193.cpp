#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k;
  cin >> k;
  int curlayerel = -1;
  int startel = 1;
  int sum = 0;
  int layer = 0;
  int prev = 0;
  while (k >= startel) {
    curlayerel += 2;
    sum += curlayerel;
    prev = startel;
    startel = sum + 1;
    layer++;
  }
  int m = k - prev + 1;
  if (m <= layer) {
    cout << m << " " << layer;
  } else
    cout << layer << " " << layer - (m - layer);
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
