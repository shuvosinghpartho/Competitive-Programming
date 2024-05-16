/*#include <bits/stdc++.h>
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


#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, range;

    cout << "Enter an integer: ";
    cin >> n;

    cout << "Enter range: ";
    cin >> range;
    
    for (int i = 1; i <= range; ++i) {
        cout << n << " * " << i << " = " << n * i << endl;
    }
    
    return 0;
}