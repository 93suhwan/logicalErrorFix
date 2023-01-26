#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, long long> m;
  string word;
  char c;
  long long t, time = 0;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    for (long long j = 0; j < 26; j++) {
      cin >> c;
      m[c] = j + 1;
    }
    cin >> word;
    for (long long j = 1; j < word.size(); j++)
      time += abs(m[word[j]] - m[word[j - 1]]);
    cout << time << '\n';
    time = 0;
    m.clear();
  }
}
