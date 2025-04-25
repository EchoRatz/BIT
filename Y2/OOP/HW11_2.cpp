#include <iostream>
using namespace std;

class AClass{
public:
    void nonConstFunction(){
        cout << "Non-const member func called." << "\n";
    }

    void constFunction() const{
        cout << "Const member func called." << "\n";
    }
};

void byVal(AClass obj){
    cout << "Inside byVal func:" << "\n";
    obj.nonConstFunction();
    obj.constFunction();
}

void byRef(AClass& obj){
    cout << "Inside byRef func:" << "\n";
    obj.nonConstFunction();
    obj.constFunction();
}

void byConstRef(const AClass& obj){
    cout << "Inside byConstRef func:" << "\n";
    obj.constFunction();
}

int main(){
    AClass myObj;

    byVal(myObj);
    byRef(myObj);
    byConstRef(myObj);

    return 0;
}