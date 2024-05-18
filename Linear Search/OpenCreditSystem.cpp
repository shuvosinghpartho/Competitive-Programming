/*In an open credit system, the students can choose any course they like, but there is a problem. Some
of the students are more senior than other students. The professor of such a course has found quite a
number of such students who came from senior classes (as if they came to attend the pre requisite course
after passing an advanced course). But he wants to do justice to the new students. So, he is going to
take a placement test (basically an IQ test) to assess the level of difference among the students. He
wants to know the maximum amount of score that a senior student gets more than any junior student.
For example, if a senior student gets 80 and a junior student gets 70, then this amount is 10. Be careful
that we don’t want the absolute value. Help the professor to figure out a solution.
Input
Input consists of a number of test cases T (less than 20). Each case starts with an integer n which is
the number of students in the course. This value can be as large as 100,000 and as low as 2. Next n
lines contain n integers where the i’th integer is the score of the i’th student. All these integers have
absolute values less than 150000. If i < j, then i’th student is senior to the j’th student.
Output
For each test case, output the desired number in a new line. Follow the format shown in sample
input-output section.
Sample Input
3
2
100
20
4
4
3
2
1
4
1
2
3
4
Sample Output
80
3
-1*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        int scores[n];
        for (int i = 0; i < n; i++) {
            cin >> scores[i];
        }
        int maxDifference = -1;
        int maxJuniorScore = scores[0];
        for (int i = 1; i < n; i++) {
            maxDifference = max(maxDifference, maxJuniorScore - scores[i]);
            maxJuniorScore = max(maxJuniorScore, scores[i]);
        }
        cout << maxDifference << '\n';
    }
    return 0;
}