#include <iostream>
#include "SyntaxChecker.h"
#include "GenStack.h"
using namespace std;

int main()
{
  string fileName;
  cout << "Enter the file or file path to open: " << endl; // TestFile.txt is included
  cin >> fileName;

  SyntaxChecker *checker = new SyntaxChecker();
  checker->syntaxChecker(fileName);


}
