#include <iostream>
#include "Assets.h";
int main() {
    Assets SPUEmployee01;
    Assets SPUStudent01("CSC2430");
    
    SPUStudent01.AddTag("Tag-7891");
    SPUStudent01.AddTag("Tag-1232");
    SPUStudent01.AddTag("Tag-3453");

    Assets SPUStudent02 = SPUStudent01;
    SPUEmployee01 = SPUStudent01;

    std::cout<<SPUStudent01.ToString()<<std::endl;
    std::cout<<SPUStudent02.ToString()<<std::endl;
    std::cout<<SPUEmployee01.ToString()<<std::endl;
}
