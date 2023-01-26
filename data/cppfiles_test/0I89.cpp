#include <bits/stdc++.h>
using namespace std;
struct Book {
  string name;
  int index;
  Book(string name, int index) {
    this->name = name;
    this->index = index;
  }
  bool operator<(const Book &other) const {
    for (int i = 0; i < name.size(); i++) {
      if (name[i] == other.name[i]) continue;
      if (!i)
        return name[i] < other.name[i];
      else
        return other.name[i] < name[i];
    }
    assert(false);
  }
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  string name;
  vector<Book> v;
  for (int i = 1; i < n + 1; i++) {
    cin >> name;
    v.push_back(Book(name, i));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) cout << v[i].index << " ";
  cout << '\n';
  return 0;
}
