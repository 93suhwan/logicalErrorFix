#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s1, s2, a;
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
      if (i % 2 == 0)
        s1 += a[i];
      else
        s2 += a[i];
    }
    int t1, t2;
    istringstream(s1) >> t1;
    istringstream(s2) >> t2;
    if (s2.empty())
      cout << t1 - 1;
    else
      cout << (t1 + 1) * (t2 + 1) - 2 << endl;
  }
  return 0;
}
