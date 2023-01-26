#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    long long ans = 0;
    string s;
    cin >> s;
    vector<int> letters(26);
    for (int i = 0; i <= s.size() + 1; i++) {
      letters[s[i] - 'a'] = i;
    }
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
      ans = ans + (abs(letters[s[i - 1] - 'a'] - letters[s[i] - 'a']));
    }
    cout << ans << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
}
