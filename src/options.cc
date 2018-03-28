#include "options.h"

#include <loguru.hpp>

#include <iostream>

Options ParseOptions(int argc, char** argv) {
  Options output;

  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg[0] == '-') {
      auto equal = arg.find('=');
      if (equal != std::string::npos) {
        output[arg.substr(0, equal)] = arg.substr(equal + 1);
      } else if (i + 1 < argc && argv[i + 1][0] != '-')
        output[arg] = argv[++i];
      else
        output[arg] = "";
    }
  }

  return output;
}

bool HasOption(const Options& options, const std::string& option) {
  return options.find(option) != options.end();
}
