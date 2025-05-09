// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


template <typename T>
void display(const std::deque<T> &d ) {
   std::cout << "[";
   for(const auto &elem : d)
    {
      std::cout << elem << "";
      
    }
    std::cout << "]";

}

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    
    std::cout << "va a rotarlos " << std::endl;
    std::string copyS ;

    
    for (char c : s) 
    {
      if(c != ' ' || c != ',' || c != '!' || c != '\''  ) {
        copyS += std::toupper(c);
      }

    }
    
    std::cout << copyS << std::endl;
    
    
    //s = std::remove(s.begin(), s.end(), ' ');
    
    std::deque<char> flipped ;
    
    for(const auto &elem : copyS)
    {
      flipped.push_front(elem);
    }
    
    display(flipped);
    
    
    std::string output_string = std::string(flipped.begin(), flipped.end());
    
      
    //comparelo con el string
    
    if(output_string == copyS) {
       std::cout << "is palindrome " << std::endl;
       return true;
    }

      else {
        std::cout << "is not palindrome " << std::endl;
        return false;
      }
    
 


    

}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
