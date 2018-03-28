#pragma once

#include <string>
#include <unordered_map>

using Options = std::unordered_map<std::string, std::string>;

Options ParseOptions(int argc, char** argv);

bool HasOption(const Options& options,
               const std::string& option);
