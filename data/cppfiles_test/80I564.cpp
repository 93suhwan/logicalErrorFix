#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

void test_case(){
    int n; cin >> n;
    string s; cin >> s;

    int ind = -1;
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            ind = i;
            break;
        }
    }

    if(ind == -1){
        cout << 1 << " " << n-(n%2) << " " << 1 << " " << n/2 << endl;
    }
    else{
        if(ind <= n/2){
            cout << ind+1 << " " << n << " " << ind+2 << " " << n << endl;
        }
        else{
            cout << 1 << " " << ind+1 << " " << 1 << " " << ind << endl;
        }
    }

    return;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}