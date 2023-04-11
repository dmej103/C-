#include <iostream>
using namespace std;
int main() {
    int q[8][8]  = {}, r, c = 0;


    q[0][0] = 1; //puts queens in top left space.

    nc:
        c++;
        if (c == 8) goto print;
        r = -1;

    nr:
        r++;
        if (r == 8) goto backtrack;
        
        for (int i = 0; i < c; i++) {
            if (q[r][i] == 1) goto nr;
        } // row test
        
        for (int i = 1; ((r-i)>=0 && (c-i) >= 0); i++) {
            if (q[r-i][c-i] == 1) goto nr;
        } // up diagonal

        for (int i = 1; ((r+i) < 8 && (c-i) > -1); i++) {
            if (q[r+i][c-i] == 1) goto nr;
        } //down diagonal

        q[r][c] = 1;
        goto nc;

    backtrack:
        c--;
        if (c == -1) {
            cout << "All solutions found, no more can be made.\n";
            return 0;
        }

        r = 0;
        while (q[r][c] != 1) {
            r++;
        }

        q[r][c] = 0;
        goto nr;

    print:
        static int NumSolutions = 0;
        cout << "Solution #" << ++NumSolutions << ":\n";

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << q[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        goto backtrack;
}