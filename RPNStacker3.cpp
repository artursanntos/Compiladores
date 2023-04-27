#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <regex>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Regex {
public:
  bool isNumber(string entry) {
    if (regex_match(entry, regex("[0-9]+"))) {
      return true;
    }
    return false;
  };

  bool isOperator(string entry) {
    if (regex_match(entry, regex("[+-/*]"))) {
      return true;
    }
    return false;
  };
};

class Token {
public:
  string type;
  string lexeme;

  string findOperator(string entry) {
    if (entry == "+") {
      return "PLUS";
    } else if (entry == "-") {
      return "MINUS";
    } else if (entry == "*") {
      return "STAR";
    } else {
      return "SLASH";
    }
  }

  void tokenization(string entry) {

    Regex classification;

    if (classification.isNumber(entry) || classification.isOperator(entry)) {
      if (classification.isNumber(entry)) {
        type = "NUM";
        lexeme = entry;
      } else if (classification.isOperator(entry)) {
        type = findOperator(entry);
        lexeme = entry;
      }
    } else {
      type = "Unexpected";
      lexeme = entry;
      ostringstream error;
      error << "Error: Unexpected Character: " << entry;
      cout << error.str();
    }
  };

  void toString() {
    ostringstream token;
    token << "Token [type=" << type << ", lexeme=" << lexeme << "]\n";
    cout << token.str();
  }
};

class RPN {
public:
  stack<int> RPNStacker;

  int calculator(list<Token> tokens) {
    int fstOperand;
    int sndOperand;
    int partialResult;
    int result;

    for (auto it = tokens.begin(); it != tokens.end(); it++) {

      Token token = *it;
      if (token.type == "NUM") {
        RPNStacker.push(stoi(token.lexeme));
      } else if (token.type == "PLUS") {
        fstOperand = RPNStacker.top();
        RPNStacker.pop();
        sndOperand = RPNStacker.top();
        RPNStacker.pop();

        partialResult = sndOperand + fstOperand;
        RPNStacker.push(partialResult);

      } else if (token.type == "MINUS") {
        fstOperand = RPNStacker.top();
        RPNStacker.pop();
        sndOperand = RPNStacker.top();
        RPNStacker.pop();

        partialResult = sndOperand - fstOperand;
        RPNStacker.push(partialResult);

      } else if (token.type == "STAR") {
        fstOperand = RPNStacker.top();
        RPNStacker.pop();
        sndOperand = RPNStacker.top();
        RPNStacker.pop();

        partialResult = sndOperand * fstOperand;
        RPNStacker.push(partialResult);

      } else if (token.type == "SLASH") {
        fstOperand = RPNStacker.top();
        RPNStacker.pop();
        sndOperand = RPNStacker.top();
        RPNStacker.pop();

        partialResult = sndOperand / fstOperand;
        RPNStacker.push(partialResult);
      }
    }

    result = RPNStacker.top();
    return (result);
  };
};

int main() {

  ifstream input("./input.txt"); // Open input file

  if (!input.is_open()) { // Check if file
    cerr << "Error opening input file." << endl;
    return 1;
  }

  RPN myRPN;
  string entry;

  list<Token> tokens;

  while (input >> entry) {
    Token element;
    element.tokenization(entry);
    tokens.push_back(element);
    element.toString();
  }

  input.close();
  int result;
  result = myRPN.calculator(tokens);
  cout << result;

  return 0;
}