// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
  
    std::fstream in_file;
    in_file.open("../romeoandjuliet"); //    in_file.open("../romeoandjuliet");
    
    std::string saved_file = "../formatted_novel.txt";
    
    std::fstream out_file {saved_file, std::ios::out};

    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    std::string line{};
    int num_line {0};
    while (std::getline(in_file, line)) {
        
        if (line.size() == 1) { //Waaat lo detecta a size de 1...
            std::cout << line << std::endl;
            out_file << line << std::endl; //Si quieres quitar los espacios en console
        }
        else
        {
            num_line++;
            std::cout << std::left << std::setfill(' ') << std::setw(10) << num_line;
            std::cout << line << std::endl;
            
            out_file << std::left << std::setfill(' ') << std::setw(10) << num_line;
            out_file << line << std::endl;
        }
    }
    
    in_file.close();
    std::cout << "Refactored novel was saved in " << saved_file << std::endl;

    
    return 0;
}

