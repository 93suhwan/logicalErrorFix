#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int count(string s, char c)
{
    // Count variable
    int res = 0;
 
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
    return ans;
}
bool isPalindrome(string S)
{
    // Iterate over the range [0, N/2]
    for (int i = 0; i < S.length() / 2; i++) {
 
        // If S[i] is not equal to
        // the S[N-i-1]
        if (S[i] != S[S.length() - i - 1]) {
            // Return No
            return false;
        }
    }
    // Return "Yes"
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
        long long val=INT_MAX;
        for(char c='a';c<='z';c++){
            string j = s;
            long long cnt = count(j,c);
            long long match = cntm(s,c);
            j.erase(remove(j.begin(), j.end(), c), j.end());
            if(c=='k' || c=='h' || c=='y'){
                // cout<<j<<" "<<c<<"\n";
            }
            bool ans = isPalindrome(j);
            if(ans){
                val = min(val,cnt-match);
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