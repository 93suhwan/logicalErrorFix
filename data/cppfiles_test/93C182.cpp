#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> mp;
bool cmp(pair<long long int, long long int> tb,
         pair<long long int, long long int> ta) {
  if (ta.first == tb.first)
    return tb.second < ta.second;
  else
    return ta.first < tb.first;
}
void xc() {
  mp[0] = 0;
  for (long long int i = 1; i <= 300005; i++) {
    mp[i] = (mp[i - 1] ^ i);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  xc();
  long long int t, i, j, l, sum = 0, n, a, b;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> a >> b;
    sum = a;
    n = mp[a - 1];
    if (n == b)
      cout << sum << endl;
    else {
      if ((n ^ b) == a)
        sum += 2;
      else
        sum++;
      cout << sum << endl;
    }
  }
}
