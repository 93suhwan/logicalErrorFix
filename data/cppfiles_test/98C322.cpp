#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
void sieve() {
  vector<bool> isComposite(100000000, false);
  for (int i = 2; i * i <= 100000000; i++) {
    if (isComposite[i] == false)
      for (int j = i * 2; j <= 100000000; j += i) isComposite[j] = true;
  }
  for (int i = 2; i <= 100000000; i++)
    if (isComposite[i] == false) primes.push_back(i);
  for (auto it : primes) cout << it << " ";
}
long long LCM(int n) {
  long long lcm = 1;
  for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
    int pp = primes[i];
    while (pp * primes[i] <= n) pp = pp * primes[i];
    lcm *= pp;
    lcm %= 1000000007;
  }
  return lcm;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    string keyboard;
    string s;
    cin >> keyboard;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < keyboard.size(); i++) {
      mp[keyboard[i]] = i + 1;
    }
    long long int time = 0;
    for (int i = 1; i < s.length(); i++) {
      time += abs((mp[s[i]] - mp[s[i - 1]]));
    }
    cout << time << "\n";
  }
}
