#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
struct segment {
  int start;
  int end;
};
struct monster {
  int a;
  int b;
  int nof_to_kill;
  monster(int attack, int health) {
    a = attack;
    b = health;
  }
  bool operator<(const monster &new_monster) const {
    return (nof_to_kill * a < new_monster.nof_to_kill * new_monster.a);
  }
};
void solution() {
  int64_t n{};
  cin >> n;
  cout << -n + 1 << " " << n << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
