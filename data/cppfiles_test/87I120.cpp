#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
int main() {
    int t; cin >> t; 
    while(t--) {
        int y, n; cin >> y >> n;
        ordered_set myset;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            int index = myset.order_of_key(x);
            ans += index;
            myset.insert(x);
        }
        cout << ans << endl;
    }
}
