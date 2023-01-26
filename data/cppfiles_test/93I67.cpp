#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long int, long long int> tb,
         pair<long long int, long long int> ta) {
  if (ta.first == tb.first)
    return tb.second < ta.second;
  else
    return ta.first < tb.first;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t, i, j, l, sum = 0, n, a, b;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> a >> b;
    sum = a;
    long long int f = 1;
    n = 0;
    if (sum == 1 && b == 1) sum += 2;
    if (a % 2) n = a - 1;
    if ((n ^ b) < a) {
      if (b == 0) sum++;
    } else if ((n ^ b) > a) {
      sum++;
    }
    cout << sum << endl;
  }
}
