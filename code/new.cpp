/*// problem 1


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                count++;
            }
        }
    }
        cout << count << endl;

    return 0;
}*/


// problem 2


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int c = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] >= a[k - 1] && a[i] > 0) {
            c++;
        }
    }
    cout << c << endl;

    return 0;
}



/*// problem 3


#include <bits/stdc++.h>
using namespace std;

int main() {
    int j;
    cin >> j;

    int a = 0, b = 0, c = 0, s;
    
    for(int i = 0; i < j; i++) {
        cin >> s;
        a += s;
    }

    for(int i = 0; i < j - 1; i++) {
        cin >> s;
        b += s;
    }

    for(int i = 0; i < j - 2; i++) {
        cin >> s;
        c += s;
    }

    cout << a - b << endl;
    cout << b - c << endl;

    return 0;
}



// problem 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4];
    for(int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            if(a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for(int i = 1; i < 4; i++) {
        cout << a[0] - a[i] << " ";
    }
    
    return 0;
}*/


