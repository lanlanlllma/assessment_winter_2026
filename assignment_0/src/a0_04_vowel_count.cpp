#include <cctype>
#include <iostream>
#include <string>


int main() {
  std::string line;
  if (std::getline(std::cin, line)){
    std::size_t count = 0;
    for(char ch : line){
      char lower = std::tolower(static_cast<unsigned char>(ch));
      if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'){
        ++count;
      }
    }
    std::cout << count << std::endl;
  }

  return 0;
}
