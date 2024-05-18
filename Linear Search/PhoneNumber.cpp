/*Let's call a string a phone number if it has length 11 and fits the pattern "8xxxxxxxxxx", where each "x" is replaced by a digit.

For example, "80123456789" and "80000000000" are phone numbers, while "8012345678" and "79000000000" are not.

You have n
 cards with digits, and you want to use them to make as many phone numbers as possible. Each card must be used in at most one phone number, and you don't have to use all cards. The phone numbers do not necessarily have to be distinct.

Input
The first line contains an integer n
 — the number of cards with digits that you have (1≤n≤100
).

The second line contains a string of n
 digits (characters "0", "1", ..., "9") s1,s2,…,sn
. The string will not contain any other characters, such as leading or trailing spaces.

Output
If at least one phone number can be made from these cards, output the maximum number of phone numbers that can be made. Otherwise, output 0.

Examples
Inputcopy	Outputcopy
11
00000000008
1
Inputcopy	Outputcopy
22
0011223344556677889988
2
Inputcopy	Outputcopy
11
31415926535
0
Note
In the first example, one phone number, "8000000000", can be made from these cards.

In the second example, you can make two phone numbers from the cards, for example, "80123456789" and "80123456789".

In the third example you can't make any phone number from the given cards.*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int count = 0;
    string s; cin >> s;
    if ( n >= 11) {
        for ( int i = 0; i < n; i++) {
            if (s[i] == '8') {
                count++;
            }
        }
        if (count < n / 11) {
            cout << count << '\n';
        }
        else {
            cout << n / 11 << '\n';
        }
    }
    else {
        cout << "0" << '\n';
    }

    return 0;
}