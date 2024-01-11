using namespace std;

bool isPalindrome(string str) {
  // Write your code here.
  if (str.length() == 0){
    return true;
  }

  for(int i = 0, z = str.length() -1; i <= z; i++, z--){
    if (str[i] != str[z]) return false;
    
  }
  return true;
}
