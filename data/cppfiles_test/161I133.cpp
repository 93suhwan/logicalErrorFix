#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#define BiSso ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//typedef tree<int, null_type, less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> od;
const int N = 1e3+5 , M = 1e5 , lg =__lg(N) + 10 , MOD = 1e9+7 , base = 31 ;
int tc,n,x,y,ans[N];
pair<int , int>ar[N];
int main(){
    BiSso
    #ifndef ONLINE_JUDGE
       freopen("input.in","r",stdin);
       //order_of_key(k) numbers of ele that stricly smaller than k
       //find_by_order(k) iterator on kth element in st (zero_based)
    #endif
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        set<pair<int , int>>st;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            ar[i]={x,y};
            st.insert({x,y});
        }
        for(int i=0;i<n;i++)
        {
            if(ar[i].first==ar[i].second)
            {
                ans[i]=ar[i].first;
                continue;
            }
            pair<int ,int>p1={0,0},p2={0,0};
            for(int s_t=ar[i].first;s_t<=ar[i].second;s_t++)
            {
                if(ar[i].first<=s_t-1)
                {
                    p1={ar[i].first,s_t-1};
                }
                if(s_t+1<=ar[i].second)
                {
                    p2={s_t+1,ar[i].second};
                }
                if(p1.first>0&&p2.first>0&&st.find(p1)!=st.end()&&st.find(p2)!=st.end())
                {
                    ans[i]=s_t;
                    break;
                }
                if(p1.first>0&&st.find(p1)!=st.end())
                {
                    ans[i]=s_t;
                    break;
                }
                if(p2.first>0&&st.find(p2)!=st.end())
                {
                    ans[i]=s_t;
                    break;
                }
            }
            st.erase(st.find(ar[i]));
        }
            for(int i=0;i<n;i++)printf("%d %d %d\n",ar[i].first,ar[i].second,ans[i]);
            puts("");
        }
    return 0;
}
