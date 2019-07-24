#include <iostream>

using namespace std;

class Operations{
    private:
        float a;
        int b, c;
    public:
        Operations(float x, int y){
            a = x;
            b = y;
        }
        void Checklights(){
            if ((a > b) || (b == 1)){
                c = 1;
                cout << "Lights ON" << endl;
            }
            else{
                c =  0;
                cout << "Lights OFF" << endl;
            }
        }
};

int main()
{
    Operations op(0,0);
    op.Checklights();
    return 0;
}