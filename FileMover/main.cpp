#include <filesystem>
#include <iostream>
int main() {

    std::string pathFrom;// = "C:\\Users\\Milosz\\Desktop\\test\\test.txt";
    std::string pathTo;// = "C:\\Users\\Milosz\\Desktop\\test.txt";
    std::string fileName;

    std::cout << "Insert path of file you want to move:" << std::endl;
    std::cin >> pathFrom;

    std::cout << "Insert name of file:" << std::endl;
    std::cin >> fileName;

    std::cout << "Insert path where you want to move file:" << std::endl;
    std::cin >> pathTo;


    try {
        std::filesystem::copy_file(pathFrom+fileName, pathTo+fileName);
        std::cout << "File copied" << std::endl;
    }
    catch (std::filesystem::filesystem_error& e) {
        std::cout << e.what() << std::endl;
        std::cin.get();
        return 1;
    }

    try {
        std::filesystem::remove(pathFrom+fileName);
        std::cout << "File removed" << std::endl;
    }
    catch (std::filesystem::filesystem_error& e) {
        std::cout<< e.what() << std::endl;
        std::cin.get();
        return 1;
    }

    std::cin.get();
}