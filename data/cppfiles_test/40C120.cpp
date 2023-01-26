#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long f = 0; f < t; f++) {
    int m;
    cin >> m;
    vector<vector<long long> > v;
    for (int i = 0; i < 2; i++) {
      vector<long long> x;
      for (int i = 0; i < m; i++) {
        long long temp;
        cin >> temp;
        ;
        x.push_back(temp);
      }
      v.push_back(x);
    }
    long long score = INT_MAX;
    vector<vector<long long> > a(2, vector<long long>(m, 0));
    a = v;
    a[0][0] = 0;
    a[1][m - 1] = 0;
    long long pref = a[1][0];
    int temp;
    for (int i = 1; i < m; i++) {
      temp = a[1][i];
      a[1][i] = pref;
      pref += temp;
    }
    pref = a[0][m - 1];
    for (int i = m - 2; i >= 0; i--) {
      temp = a[0][i];
      a[0][i] = pref;
      pref += temp;
    }
    a[1][0] = 0;
    a[0][m - 1] = 0;
    for (int i = 0; i < m; i++) {
      score = min(score, max(a[1][i], a[0][i]));
    }
    cout << score;
    cout << "\n";
  }
  return 0;
}
