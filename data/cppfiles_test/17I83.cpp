#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    ordered_set osp,osn;
    osp.insert(x);
    osn.insert(-x);
    int ans = 0;
    for(int i=1;i<n;i++){
        cin >> x;
        int leftPlacedInversions = osp.order_of_key(x);
        int rightPlacedInversions = osn.order_of_key(-x);
        ans += min(leftPlacedInversions,rightPlacedInversions);
        osp.insert(x);
        osn.insert(-x);
    }
    cout << ans << "\n";
}
int32_t main(){
    int t;
    cin >> t;
    while(t--)
    solve();

    return 0;
}
