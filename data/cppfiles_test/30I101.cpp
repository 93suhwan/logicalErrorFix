#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

long long count(string s, char c)
{
    // Count variable
    long long res = 0;
 
    for (int i=0;i<s.length();i++)
 
        // checking character in string
        if (s[i] == c)
            res++;
 
    return res;
}

long long cntm(string s,char j){
    long long low = 0;
    long long high = s.size()-1;
    long long ans=0;
    while(low<high){
        if(s[low]==s[high] && (s[low]==j)){
            ans+=2;
        }
        low++;
        high--;
    }
    low=0;
    high=s.size()-1;
    if(s[s.size()/2]==j){
        if(s[s.size()/2-1]==s[s.size()/2+1]){
            ans++;
        }
    }
    return ans;
}
bool isPalindrome(string s)
{
    long long low=0;
    long long high = s.size()-1;
    while(low<high){
        if(s[low++]!=s[high--]){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){	
        long long n;
        cin>>n;
        string s;
        cin>>s;
        bool ans1 = isPalindrome(s);
        if(ans1){
            cout<<0<<"\n";
            continue;
        }
        long long val=INT_MAX;
        set<int> st(s.begin(),s.end());
        for(auto c : st){
            long long low = 0;
            long long high = s.size()-1;
            long long cnt = 0;
            string j  = s;
            while(low<high){
                if(s[low]!=s[high]){
                    if(s[low]==c || s[high]==c){
                        cnt++;  
                    }
                }
                string j = s;
                
                low++;
                high--;
            }
            j.erase(remove(j.begin(), j.end(), c), j.end());
            bool ans = isPalindrome(j);
            if(ans){
                val = min(val,cnt);
            }
        }
        if(val==INT_MAX){
            cout<<-1<<"\n";
        }
        else{
            cout<<val<<"\n";
        }
    }
    return 0;
}