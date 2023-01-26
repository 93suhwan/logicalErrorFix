#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long ti = 1;
  cin >> ti;
  for (long long i = 0; i < ti; i++) {
    long long w, h;
    cin >> h >> w;
    long long q1;
    cin >> q1;
    vector<long long> qb1(q1);
    for (long long i = 0; i < q1; i++) {
      cin >> qb1[i];
    }
    long long b1 = abs(qb1[0] - qb1[q1 - 1]);
    long long h1 = w;
    long long q2;
    cin >> q2;
    vector<long long> qb2(q2);
    for (long long i = 0; i < q2; i++) {
      cin >> qb2[i];
    }
    long long b2 = abs(qb2[0] - qb2[q2 - 1]);
    long long h2 = w;
    long long q3;
    cin >> q3;
    vector<long long> qb3(q3);
    for (long long i = 0; i < q3; i++) {
      cin >> qb3[i];
    }
    long long b3 = abs(qb3[0] - qb3[q3 - 1]);
    long long h3 = h;
    long long q4;
    cin >> q4;
    vector<long long> qb4(q4);
    for (long long i = 0; i < q4; i++) {
      cin >> qb4[i];
    }
    long long b4 = abs(qb4[0] - qb4[q4 - 1]);
    long long h4 = h;
    cout << max({b1 * h1, b2 * h2, b3 * h3, b4 * h4}) << "\n";
  }
}
