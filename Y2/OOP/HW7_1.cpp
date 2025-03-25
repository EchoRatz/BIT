#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Text{
private:
    std::string textContent;

public:
    Text() : textContent(""){}

    Text(const std::string& fileName){
        std::ifstream file(fileName);
        if (file){
            std::ostringstream ss;
            ss << file.rdbuf();
            textContent = ss.str();
        } else{
            std::cerr << "Error: File could not open " << fileName << "\n";
        }
    }

    std::string contents() const{
        return textContent;
    }
};

int main(){
    Text myText("example.txt");
    std::cout << "File content:\n" << myText.contents() << "\n";

    return 0;
}
