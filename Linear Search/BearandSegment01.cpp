/*Read problems statements in Mandarin Chinese, Russian and Vietnamese as well.
Bear Limak has a string S. Each character of S is a digit '0' or '1'.

Help Limak and check if all the '1' digits form a single non-empty segment (consecutive subsequence) in the string. For each test case, print "YES" or "NO" accordingly.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The only line of each test case contains one string S, consisting of digits '0' and '1' only.

Output
For each test case, output a single line containing the answer — "YES" if all the '1' digits form a single non-empty segment, and "NO" otherwise. Don't print the quotes.

Constraints
1 ≤ T ≤ 10
1 ≤ |S| ≤ 105 (here, |S| denotes the length of S)
Subtasks
Subtask #1 (50 points): 1 ≤ |S| ≤ 50
Subtask #2 (50 points): Original constraints.
Sample 1
Inputcopy	Outputcopy
6
001111110
00110011
000
1111
101010101
101111111111
YES
NO
NO
YES
NO
NO
The answer is "YES" for strings 001111110 and 1111.

The answer is "NO" for 00110011 because the '1' digits form two disjoint segments (while they should all be consecutive, with no '0' digits between them).

The answer is "NO" for 000 because the segment formed by the '1' digits must be non-empty (as written in the statement).*/



#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
        string s; cin>>s;
        int ct=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
                ct++;
        }
        int index;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                index=i;
                break;
            }
        }
        int check=0;
        for(int i=index;i<s.length();i++){
            if(s[i]=='1')
                check++;
            else
                break;
        }
        if(check==ct && ct>0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
	}
	return 0;
}
