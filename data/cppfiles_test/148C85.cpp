#include <bits/stdc++.h>
using namespace std;
long long int s1_size, s2_size, f_size, c_size;
long long int area(long long int base, long long int top) { return base * top; }
long long int solve(long long int rectx, long long int recty,
                    vector<long long int> s1, vector<long long int> s2,
                    vector<long long int> f, vector<long long int> c) {
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  sort(f.begin(), f.end());
  sort(c.begin(), c.end());
  long long int ans[4];
  long long int bottom = s1[0];
  long long int top = s1[s1_size - 1];
  ans[0] = area(abs(bottom - top), recty);
  bottom = s2[0];
  top = s2[s2_size - 1];
  ans[1] = area(abs(bottom - top), recty);
  bottom = f[0];
  top = f[f_size - 1];
  ans[2] = area(abs(bottom - top), rectx);
  bottom = c[0];
  top = c[c_size - 1];
  ans[3] = area(abs(bottom - top), rectx);
  sort(ans, ans + 4);
  return ans[3];
}
int main() {
  long long int length, t;
  cin >> length;
  long long int ans[length];
  vector<long long int> s1;
  vector<long long int> s2;
  vector<long long int> f;
  vector<long long int> c;
  for (long long int index = 0; index < length; index++) {
    f.clear();
    c.clear();
    s2.clear();
    s1.clear();
    long long int rectx, recty;
    cin >> rectx >> recty;
    cin >> s1_size;
    for (long long int i = 0; i < s1_size; i++) {
      cin >> t;
      s1.push_back(t);
    }
    cin >> s2_size;
    for (long long int i = 0; i < s2_size; i++) {
      cin >> t;
      s2.push_back(t);
    }
    cin >> f_size;
    for (long long int i = 0; i < f_size; i++) {
      cin >> t;
      f.push_back(t);
    }
    cin >> c_size;
    for (long long int i = 0; i < c_size; i++) {
      cin >> t;
      c.push_back(t);
    }
    ans[index] = solve(rectx, recty, s1, s2, f, c);
  }
  for (long long int i = 0; i < length; i++) {
    cout << ans[i] << "\n";
  }
}
