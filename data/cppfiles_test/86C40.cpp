#include <bits/stdc++.h>
using namespace std;
void precision(int a) { cout << setprecision(a) << fixed; }
vector<int> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = (long long(i) * long long(i)); j <= n; j += i)
        arr[j] = 1;
    }
  return vect;
}
static bool comp(const pair<long long, long long>& a,
                 const pair<long long, long long>& b) {
  return a.second < b.second;
}
const long long N = 3e5 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<string> v;
    string s1, s2;
    cin >> s1 >> s2;
    v.push_back(s1);
    v.push_back(s2);
    long long cnt0 = 0, cnt1 = 0;
    for (long long i = 0; i < (2); i++) {
      for (long long j = 0; j < (n); j++) {
        if (v[i][j] == '0')
          cnt0++;
        else
          cnt1++;
      }
    }
    if (cnt0 == 0)
      cout << 0 << "\n";
    else if (cnt1 == 0)
      cout << n << "\n";
    else {
      long long cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
      for (long long i = 0; i < (n); i++) {
        if ((v[0][i] == '0' && v[1][i] == '1') ||
            (v[0][i] == '1' && v[1][i] == '0'))
          cnt2++;
        else if (v[0][i] == '0' && v[1][i] == '0') {
          if (i < n - 1 && v[0][i + 1] == '1' && v[1][i + 1] == '1') {
            cnt3++;
            i++;
          } else
            cnt4++;
        } else if (v[0][i] == '1' && v[1][i] == '1') {
          if (i < n - 1 && v[0][i + 1] == '0' && v[1][i + 1] == '0') {
            cnt5++;
            i++;
          }
        }
      }
      cout << 2 * cnt2 + 2 * cnt3 + cnt4 + 2 * cnt5 << "\n";
    }
  }
  return 0;
}
