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
bool isGoogles = 0;
bool testcase = 1;
void achilles() {
  long long n;
  cin >> n;
  string arr1, arr2;
  cin >> arr1 >> arr2;
  for (long long j = 0; j < n; j++) {
    if (arr1[j] == arr2[j] && arr1[j] == '1') {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
