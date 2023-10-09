#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int round(float n){
    if(n - (int) n < 0.5)
        return (int)n;
    return (int)(n + 1);
} 


void DDA(int x0, int y0, int xn, int yn){
    int dx = xn - x0;
    int dy = yn - y0;

    int step;

    if(abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
    
    cout << setw(5) << "xp" << setw(5) << "yp" << setw(5) << "1-xp" << setw(5) << "yp-m"<< setw(10) << " " << "round of (1-xp, yp-m)" << endl;

    if (step < 1) {
        // Jika step < 1, gunakan rumus xp+1 = round(xp-1) dan yp+1 = round(yp-m)
        float x = x0;
        float y = y0;
        for (int i = 0; i < step; i++) {
            cout << setw(5) << x0 << setw(5) << y0 << setw(5) << x << setw(5) << y << setw(10) << "(" << x << " , " << y << endl;
            // cout << x << " " << y << "\n";
            // std::cout << std::round(x) << " " << std::round(y) << "\n";
            x = std::round(x0 - 1);
            y = std::round(y0 - step);
        }
    }
    else {
        // Gunakan rumus DDA biasa
        float x_incr = (float)dx / step;
        float y_incr = (float)dy / step;
        float x = x0;
        float y = y0;

        for (int i = 0; i < step; i++) {
            cout << setw(5) << x0 << setw(5) << y0 << setw(5) << x << setw(5) << y << setw(10) << "(" << x << " , " << y << ")"<< endl;
            // cout << x << " " << y << "\n";
            // std::cout << std::round(x) << " " << std::round(y) << "\n";
            x += x_incr;
            y += y_incr;
        }
    }
}
    

int main(){
    int x0 = 12, y0 = 1, xn = 2, yn = 8;

    DDA(x0, y0, xn, yn);

    return 0;
}