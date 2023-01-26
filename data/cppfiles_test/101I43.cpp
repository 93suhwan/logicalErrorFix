#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TT;
  cin >> TT;
  for (int tt = 1; tt <= TT; tt++) {
    cin >> n;
    a.resize(n);
    for (auto& i : a) cin >> i;
    cin >> s;
    int lessB = 0, moreR = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B')
        lessB += (a[i] <= 1);
      else
        moreR += (a[i] >= n);
    }
    if (lessB > 1 or moreR > 1)
      cout << "NO\n";
    else
      cout << "yes\n";
  }
  return 0;
}
