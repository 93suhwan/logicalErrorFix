#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool cmp(string s1, string s2) {
  int k = s1.size();
  for (int i = 0; i < k; i++) {
    if ((i + 1) % 2 == 1) {
      if (s1[i] > s2[i]) {
        return false;
      }
    } else {
      if (s1[i] < s2[i]) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s1;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    s1.push_back(s);
  }
  vector<string> s2 = {s1.begin(), s1.end()};
  sort(s1.begin(), s1.end(), cmp);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s1[i] == s2[j]) {
        cout << j + 1 << " ";
        break;
      }
    }
  }
  return 0;
}
