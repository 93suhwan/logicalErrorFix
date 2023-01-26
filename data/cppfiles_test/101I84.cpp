#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
const unsigned int M = 1000000007;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> T_set; // PBDS_set
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> T_multiset; // PBDS_multiset
bool comparator(pair<int,int> p1, pair<int, int> p2){
    if(abs(p1.first - p1.second) != abs(p2.first - p2.second))
    return abs(p1.first - p1.second) < abs(p2.first - p2.second);
    else if(p1.first != p2.first)
    return p1.first < p2.first;
    return p1.second < p2.second;
}
void solve()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> x(n);
        string s;
        for(int &elem : x)
        cin>>elem;
        cin>>s;
        vector<pair<int,int>> interval;
        for(int i = 0; i < n ; i ++){
            if(s[i] == 'B')
            interval.push_back({1,min(n,x[i])});
            else 
             interval.push_back({max(1,x[i]),n});           
        }        
        sort(interval.begin(),interval.end(),comparator);
        set<int> elems;
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto elem : interval){
            if(elem.first == elem.second) {
                elems.insert(elem.first);
            }
            for(int i = elem.first ; i<= elem.second; i ++){
                if(elems.find(i) == elems.end()){
                    elems.insert(i);
                    break;
                }
            }
        }
        if(elems.size() == n) cout<<"YES\n";
        else cout<<"NO\n";

        



    }
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}