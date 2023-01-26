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
    string a, b;
    cin >> a >> b;
    map<char, int> letters;
    for (int i = 0; i < a.length(); i++) {
      letters[a[i]] = i + 1;
    }
    int ans = 0;
    for (int i = 0; i < b.length() - 1; i++) {
      ans += abs(letters[b[i + 1]] - letters[b[i]]);
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
