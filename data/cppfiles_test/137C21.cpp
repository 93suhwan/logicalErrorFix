#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
string helper(string t) {
  while (t.back() == '0') {
    t.pop_back();
  }
  reverse(t.begin(), t.end());
  return t;
}
string decToBinary(long long n) {
  string num = "";
  while (n > 0) {
    num += to_string(n % 2);
    n = n / 2;
  }
  return num;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long x, y;
  cin >> x >> y;
  set<string> used;
  queue<string> q;
  q.push(decToBinary(x));
  used.insert(decToBinary(x));
  while (!q.empty()) {
    string temp = q.front();
    q.pop();
    if (temp.size() > 100) {
      continue;
    }
    for (long long i = 0; i < 2; i++) {
      string temp2 = helper(temp + string(1, char('0' + i)));
      if (!used.count(temp2)) {
        used.insert(temp2);
        q.push(temp2);
      }
    }
  }
  if (used.count(decToBinary(y))) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
