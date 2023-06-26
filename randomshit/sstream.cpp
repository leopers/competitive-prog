#include <iostream> 
#include <sstream>
#include <string>

int main(){
  std::string s = "jahfkjfkjh 67 kjakfjakjf67";
  std::stringstream s2(s);

  int f;
  s2 >> f;
  std::cout << f;
}

