#include <bits/stdc++.h>
using namespace std;
int q = 1;
unsigned long long mn, j, s, n, s1;
vector<long long> v, v1;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  setlocale(LC_ALL, "Russian");
  cin >> q;
  while (q--) {
    v.clear();
    v1.clear();
    mn = 100;
    j = 0;
    s = 1;
    cin >> n;
    while (n > 0) {
      v.push_back(n % 10);
      n /= 10;
    }
    reverse(v.begin(), v.end());
    for (int i = 1; i <= 64; i++) {
      j = 0;
      v1.clear();
      s1 = s;
      while (s1 > 0) {
        v1.push_back(s1 % 10);
        s1 /= 10;
      }
      reverse(v1.begin(), v1.end());
      for (int l = 0; l < v.size() && j < v1.size(); l++) {
        if (v[l] == v1[j]) j++;
      }
      s *= 2;
      mn = min(mn, v.size() - j + v1.size() - j);
    }
    cout << mn << endl;
  }
}
