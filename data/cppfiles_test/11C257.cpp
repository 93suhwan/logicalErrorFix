#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  cin >> t;
  long long t1 = t;
  while (t1--) {
    long long n;
    cin >> n;
    vector<long long> a1;
    vector<long long> b1;
    vector<long long> c1, d1, e1;
    for (long long i = 0; i < n; i++) {
      string s;
      cin >> s;
      long long c_a = 0, c_b = 0, c_c = 0, c_d = 0, c_e = 0;
      for (long long j = 0; j < s.length(); j++) {
        if (s[j] == 'a') c_a++;
        if (s[j] == 'b') c_b++;
        if (s[j] == 'c') c_c++;
        if (s[j] == 'd') c_d++;
        if (s[j] == 'e') c_e++;
      }
      long long len = s.length();
      a1.push_back(2 * c_a - len);
      b1.push_back(2 * c_b - len);
      c1.push_back(2 * c_c - len);
      d1.push_back(2 * c_d - len);
      e1.push_back(2 * c_e - len);
    }
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
    sort(c1.begin(), c1.end());
    sort(d1.begin(), d1.end());
    sort(e1.begin(), e1.end());
    long long ans = 0;
    long long sum = 0;
    long long per = 0;
    for (long long i = a1.size() - 1; i >= 0; i--) {
      sum += a1[i];
      if (sum <= 0) break;
      per++;
    }
    ans = max(ans, per);
    sum = 0;
    per = 0;
    for (long long i = b1.size() - 1; i >= 0; i--) {
      sum += b1[i];
      if (sum <= 0) break;
      per++;
    }
    ans = max(ans, per);
    sum = 0;
    per = 0;
    for (long long i = c1.size() - 1; i >= 0; i--) {
      sum += c1[i];
      if (sum <= 0) break;
      per++;
    }
    ans = max(ans, per);
    sum = 0;
    per = 0;
    for (long long i = d1.size() - 1; i >= 0; i--) {
      sum += d1[i];
      if (sum <= 0) break;
      per++;
    }
    ans = max(ans, per);
    sum = 0;
    per = 0;
    for (long long i = e1.size() - 1; i >= 0; i--) {
      sum += e1[i];
      if (sum <= 0) break;
      per++;
    }
    ans = max(ans, per);
    cout << ans << endl;
  }
  return 0;
}
