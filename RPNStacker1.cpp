#include <cmath>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  stack<int> RPNStacker;
  string entry;
  const char *operators[5] = {"+", "-", "*", "/", "^"};
  int fstOperand;
  int sndOperand;
  float partialResult;
  int result;

  while (cin >> entry) {

    if (entry == "+") {
      sndOperand = RPNStacker.top();
      RPNStacker.pop();
      fstOperand = RPNStacker.top();
      RPNStacker.pop();

      partialResult = fstOperand + sndOperand;
      RPNStacker.push(partialResult);

    } else if (entry == "-") {
      sndOperand = RPNStacker.top();
      RPNStacker.pop();
      fstOperand = RPNStacker.top();
      RPNStacker.pop();

      partialResult = fstOperand - sndOperand;
      RPNStacker.push(partialResult);

    } else if (entry == "*") {
      sndOperand = RPNStacker.top();
      RPNStacker.pop();
      fstOperand = RPNStacker.top();
      RPNStacker.pop();

      partialResult = fstOperand * sndOperand;
      RPNStacker.push(partialResult);

    } else if (entry == "/") {
      sndOperand = RPNStacker.top();
      RPNStacker.pop();
      fstOperand = RPNStacker.top();
      RPNStacker.pop();

      partialResult = fstOperand / sndOperand;
      RPNStacker.push(partialResult);

    } else if (entry == "^") {
      sndOperand = RPNStacker.top();
      RPNStacker.pop();
      fstOperand = RPNStacker.top();
      RPNStacker.pop();

      partialResult = pow(fstOperand, sndOperand);
      RPNStacker.push(partialResult);

    } else {
      RPNStacker.push(stoi(entry));
    }
  }

  result = RPNStacker.top();
  cout << result;

  return 0;
}