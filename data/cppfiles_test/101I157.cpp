#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define pb push_back
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ld PI=acos(-1);

/*
    ordered_set o_set;
    order_of_key (k) : Number of items strictly smaller than k .
    find_by_order(k) : K-th element in a set (counting from zero). return an iterator
*/
const long long N = 1e6+5 , M = 1e9+7 , OO = 1e18 , M1 = 1e9+7 , M2 = 1e9+9 , p1 = 31 , p2 = 47;


void test_case(){

    ll n; cin>>n;

    deque<ll> arr(n);

    for (int i = 0 ; i < n ; ++i) cin>>arr[i];

    string str; cin>>str;

    priority_queue<ll> B,R;

    for (int i = 0 ; i < n ; ++i){
        if (str[i] == 'B') B.push(-arr[i]);
        else R.push(-arr[i]);
    }

    ll cnt = 1;
    ll x,y;
    while(true){

        if (B.size()){
            x = -B.top();
        }
        else x = -OO;
        if (R.size()) y = -R.top();
        else y = OO;

        //cout<<x<<" "<<y<<'\n';

        if (x == cnt){
            if (B.size()) B.pop();
            else break;
        }
        else if (y <= cnt){
            if (R.size()) R.pop();
            else break;
        }
        else if (x > cnt){
            if (B.size()) B.pop();
            else break;
        }
        else {
            break;
        }
        cnt++;

    }
    cnt--;

    if (cnt == n) cout<<"YES\n";
    else cout<<"NO\n";
}




int main() {

    FIO
    //freopen("xmore.in", "rt", stdin);
    //freopen("lepus.out", "wt", stdout);
    int tc = 1;
    cin >> tc;
    while(tc--){
        test_case();
    }

    return 0;
}
