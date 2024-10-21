#include<iostream>
using namespace std;

class Rectangle{
    int x;
    int y;
public:
    //초기화
    Rectangle(int x2, int y2) : x(x2), y(y2){}

    void SetLength(int x2, int y2){
        x = x2;
        y = y2;
    }
    // int Circumference() const{
    //     return 2 * (x + y);
    // }
    // int Area() const{
    //     return x * y;
    // }
    int printInfo()const{
       // cout << 4<< endl;
        cout << 2 * (x + y) << " " <<  x * y  << endl;
        
       // cout << 5<< endl;
    };
     
};

int main() {
    int x1, y1, x2, y2;
    cin>>x1 >> y1;

    Rectangle R1(x1, y1);
    const Rectangle R2(x1, y1);

    cin >> x2 >> y2;
    //cout << 1<< endl;
    R1.SetLength(x2, y2);
    //cout << 2<< endl;
    R1.printInfo();
    //cout << 3 << endl;
    R2.printInfo();
    // cout << 58 << endl;
    return 0;
}