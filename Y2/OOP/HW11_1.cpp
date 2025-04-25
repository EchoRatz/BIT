#include <iostream>
using namespace std;

void modChar(char& c){
    c = 'Z';
}

int main(){
    char myChar = 'A'; 
    cout << "Before modification: " << myChar << "\n";

    modChar(myChar);

    cout << "After modification: " << myChar << "\n";

    return 0;
}