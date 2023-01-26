#include <bits/stdc++.h>
using namespace std;
unordered_map<int, bool> use;
map<pair<int, int>, bool> mp;
int rand(int x) { return abs(rand()) % x + 1; }
bool check0(int* a) {
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j < i; j++) {
      if (mp[make_pair(a[j], a[i])]) return false;
    }
  }
  return true;
}
bool check1(int* a) {
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j < i; j++) {
      if (mp[make_pair(a[j], a[i])] == false) return false;
    }
  }
  return true;
}
bool check(int* a) { return check0(a) || check1(a); }
void solve(int n) {
  int num[10];
  use.clear();
  for (int i = 1; i <= 5; i++) {
    num[i] = rand(n);
    if (use[num[i]]) return;
    use[num[i]] = true;
  }
  if (check(num)) {
    for (int i = 1; i <= 5; i++) {
      printf("%d ", num[i]);
    }
    puts("");
    exit(0);
  }
}
int main() {
  srand(time(0));
  int n, m, u, v;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    mp[make_pair(u, v)] = true;
    mp[make_pair(v, u)] = true;
  }
  for (int i = 1; i <= 1000000; i++) {
    solve(n);
  }
  puts("-1");
  return 0;
}
