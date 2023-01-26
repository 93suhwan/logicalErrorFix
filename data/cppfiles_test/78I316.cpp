#include <bits/stdc++.h>
using namespace std;
void edit(vector<int> &skill, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    skill.push_back(x);
  }
}
void editl(vector<long long> &skill, long long n) {
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    skill.push_back(x);
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
bool isGoogles = 0;
bool testcase = 1;
void achilles() {
  long long a, b;
  cin >> a >> b;
  if (b % 2) b++;
  if (a > b / 2) {
    cout << b % a << "\n";
    return;
  } else {
    cout << b / 2 - 1 << "\n";
    return;
  }
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1, w = 1;
  if (testcase) cin >> t;
  while (t--) {
    if (isGoogles) {
      cout << "Case #" << w << ": ";
    }
    achilles();
    w++;
  }
  return 0;
}
