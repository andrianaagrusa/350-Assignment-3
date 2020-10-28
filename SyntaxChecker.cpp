#include <iostream>
#include <fstream>
#include "SyntaxChecker.h"
#include "GenStack.h"


// Takes in a file to analyze
void SyntaxChecker::syntaxChecker(string userFile)
{
  ifstream file;
  string line;

  file.open(userFile);

  GenStack <char>stack;

  int lineNum = 1;

  if (file.is_open())
  {
    while (getline(file, line))
    {
      for (int i = 0; i < line.length(); i++)
      {
        // add open delimiters to the stack
        if (line[i] == '(' || line[i] == '{' || line[i] == '[')
        {
          stack.push(line[i]);
        }

        // test if end delimeters have and open in the correct spot
        if (line[i] == ')')
        {
          char previous = stack.pop(); // pop the most recent open delimeter
          if (!(previous == '('))
          {
            cout << "Line " << lineNum << ": expected )" << " and found " << previous << endl;
            exit(1);
          }
        }
        else if (line[i] == '}')
        {
          char previous = stack.pop();
          if (!(previous == '{'))
          {
            cout << "Line " << lineNum << ": expected }" << " and found " << previous << endl;
            exit(1);
          }
        }
        else if (line[i] == ']')
        {
          char previous = stack.pop();
          if (!(previous == '['))
          {
            cout << "Line " << lineNum << ": expected ]" << " and found " << previous << endl;
            exit(1);
          }
        }
      }
      lineNum++; // to display which line the error occurs
    }
  }
  else
  {
    cout << "File did not open. Try again." << endl;
    exit(1);
  }

  file.close();

  // if there is an open delimiter with no end delimiter by the end of the file
  if (!(stack.isEmpty()))
  {
    char open = stack.pop();
    if (open == '(')
    {
      cout << "Reached end of file: missing )" << endl;
      exit(1);
    }
    if (open == '{')
    {
      cout << "Reached end of file: missing }" << endl;
      exit(1);
    }
    if (open == '[')
    {
      cout << "Reached end of file: missing ]" << endl;
      exit(1);
    }
  }
  else
  {
    cout << "No syntax errors were found." << endl;
  }
}
