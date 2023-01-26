#include <bits/stdc++.h>
using namespace std;
void shivam_Gupta12345() {
  long long w, h;
  cin >> w >> h;
  vector<long long> v;
  for (long long i = 0; i < 4; i++) {
    long long a;
    cin >> a;
    long long b, c;
    cin >> b;
    a--;
    while (a--) cin >> c;
    v.push_back(c - b);
  }
  long long a = max(v[0], v[1]);
  long long b = max(v[2], v[3]);
  cout << max(a * h, b * w) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) shivam_Gupta12345();
  return 0;
}
