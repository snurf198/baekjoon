#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
typedef string Command;
typedef vector<Command> Program;
typedef int ProgramInput;
typedef vector<ProgramInput> ProgramInputs;

long long MAX_VALUE = 1000000000L;
long long MIN_VALUE = -1000000000L;

vector<string> split(string str, char delimiter) {
  vector<string> result;
  stringstream stream(str);

  string temp;

  while (getline(stream, temp, delimiter)) {
    result.push_back(temp);
  }

  return result;
}

Program get_program(Command first_command) {
  Program program = vector<Command>();
  Command command;
  if (first_command == "END") return program;
  program.push_back(first_command);

  while (getline(cin, command)) {
    if (command == "END") break;
    program.push_back(command);
  }

  return program;
}

ProgramInputs get_program_inputs(int iter_counts) {
  ProgramInputs program_inputs = vector<ProgramInput>();

  for(int i = 0; i < iter_counts; i++) {
    string input;
    getline(cin, input);
    program_inputs.push_back(stoll(input));
  }

  return program_inputs;
}

string run_program(Program program, ProgramInput input) {
  vector<long long> stack = vector<long long>();
  stack.push_back(long(input));

  for (int i = 0; i < program.size(); i++) {
    Command command = program[i];
    vector<string> splitted_command = split(command, ' ');
    string oper = splitted_command[0];

    if (oper == "NUM") {
      if (splitted_command.size() < 2) {
        return "ERROR";
      }

      stack.push_back(stoll(splitted_command[1]));
    } else if (oper == "POP") {
      if (stack.size() == 0) {
        return "ERROR";
      }

      stack.pop_back();
    } else if (oper == "INV") {
      if (stack.size() == 0) {
        return "ERROR";
      }

      long long a = stack.back();
      stack.pop_back();
      stack.push_back(-a);
    } else if (oper == "DUP") {
      if (stack.size() == 0) {
        return "ERROR";
      }

      stack.push_back(stack.back());
    } else if (oper == "SWP") {
      if (stack.size() < 2) {
        return "ERROR";
      }

      long long a = stack.back();
      stack.pop_back();
      long long b = stack.back();
      stack.pop_back();
      stack.push_back(a);
      stack.push_back(b);
    } else if (oper == "ADD") {
      if (stack.size() < 2) {
        return "ERROR";
      }

      long long a = stack.back();
      stack.pop_back();
      long long b = stack.back();
      stack.pop_back();
      
      long long result = b + a;
      if (result > MAX_VALUE || result < MIN_VALUE) {
        return "ERROR";
      } 
      stack.push_back(result);
    } else if (oper == "SUB") {
      if (stack.size() < 2) {
        return "ERROR";
      }

      long long a = stack.back();
      stack.pop_back();
      long long b = stack.back();
      stack.pop_back();
      long long result = b - a;
      if (result > MAX_VALUE || result < MIN_VALUE) {
        return "ERROR";
      } 
      stack.push_back(result);
    } else if (oper == "MUL") {
      if (stack.size() < 2) {
        return "ERROR";
      }

      long long a = stack.back();
      stack.pop_back();
      long long b = stack.back();
      stack.pop_back();
      
      long long result = 1LL * b * a;
      if (result > MAX_VALUE || result < MIN_VALUE) {
        return "ERROR";
      } 
      stack.push_back(result);
    } else if (oper == "DIV") {
      if (stack.size() < 2) {
        return "ERROR";
      }

      long long a = stack.back();
      stack.pop_back();
      long long b = stack.back();
      stack.pop_back();

      if (a == 0) {
        return "ERROR";
      }
      long long result = abs(b) / abs(a);
      if ((b < 0) ^ (a < 0)) result = -result;
      if (result > MAX_VALUE || result < MIN_VALUE) {
        return "ERROR";
      } 
      stack.push_back(result);
    } else if (oper == "MOD") {
      if (stack.size() < 2) {
        return "ERROR";
      }

      long long a = stack.back();
      stack.pop_back();
      long long b = stack.back();
      stack.pop_back();

      if (a == 0) {
        return "ERROR";
      }
      long long result = abs(b) % abs(a);
      if (b < 0) result = -result;
      if (result > MAX_VALUE || result < MIN_VALUE) {
        return "ERROR";
      } 
      stack.push_back(result);
    }
  }

  if (stack.size() != 1) {
    return "ERROR";
  }

  return to_string(stack.back());
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  Command command;
  vector< vector<string> > programs_results = vector< vector<string> >();

  while(getline(cin, command)) {
    if (command.empty()) continue;
    if (command == "QUIT") {
      break;
    }

    Program program = get_program(command);
    getline(cin, command);
    int iter_count = stoi(command); 
    ProgramInputs inputs = get_program_inputs(iter_count);

    vector<string> program_results = vector<string>();
    for (int i = 0; i < inputs.size(); i++) {
      int input = inputs[i];
      program_results.push_back(run_program(program, input));
    }

    programs_results.push_back(program_results);
  }

  for (int i = 0; i < programs_results.size(); i++) {
    vector<string> program_results = programs_results[i];
    for (int j = 0; j < program_results.size(); j++) {
      string program_result = program_results[j];
      cout << program_result << "\n";
    }
    cout << "\n";
  }

  return 0;
}


