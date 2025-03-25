#include <iostream>

class Hen {
public:
    void display() {
        std::cout << "This is a Hen.\n";
    }
    
    class Nest {
    public:
        void display() {
            std::cout << "Nest inside the Hen.\n";
        }
        
        class Egg {
        public:
            void display() {
                std::cout << "Egg inside the Nest.\n";
            }
        };
    };
};

int main() {
    Hen hen;
    hen.display();
    
    Hen::Nest nest;
    nest.display();
    
    Hen::Nest::Egg egg;
    egg.display();
    
    return 0;
}