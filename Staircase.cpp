#include <bits/stdc++.h>
using namespace std;

void staircase(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=n; j>i; j--)
            cout << ' ';
        for (int j=0; j<i; j++)
            cout << '#';
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
