#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long min(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
long long max(long long a, long long b, long long c) {
  return max(a, max(b, c));
}
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main(int argc, char **argv) {
  long long t;
  cin >> t;
  for (long long ii = 0; ii < t; ii++) {
    long long n, k;
    cin >> n >> k;
    k++;
    vector<long long> banknotes;
    long long temp;
    long long howMany[10] = {0,     9,      99,      999,      9999,
                             99999, 999999, 9999999, 99999999, 999999999};
    long long values[10] = {1,      10,      100,      1000,      10000,
                            100000, 1000000, 10000000, 100000000, 1000000000};
    vector<long long> notesLeft;
    for (long long i = 0; i < n; i++) {
      cin >> temp;
      banknotes.push_back(temp);
      if (i != 0) {
        notesLeft.push_back(howMany[banknotes[i] - banknotes[i - 1]]);
      }
    }
    long long sol = 0;
    for (long long i = 0; i < notesLeft.size(); i++) {
      if (notesLeft[i] < k) {
        sol += values[banknotes[i]] * notesLeft[i];
        k -= notesLeft[i];
      } else {
        sol += values[banknotes[i]] * k;
        k = 0;
      }
    }
    if (k > 0) {
      sol += values[banknotes[banknotes.size() - 1]] * k;
    }
    cout << sol << endl;
  }
  return 0;
}
