#include "precompiled.hxx"

#include "Parser.hxx"

void parse(std::string name, std::string& output) {
  std::filesystem::path inputDir(INPUTS_DIR);
  std::filesystem::path filePath = inputDir / (name + ".txt");
  if (!std::filesystem::exists(filePath)) {
    throw std::runtime_error("File not found: " + filePath.string());
  }
  std::ifstream ifs(filePath);
  std::stringstream ss;
  ss << ifs.rdbuf();
  output = ss.str();
}

void parse(std::string name, int& output) {
  std::string input;
  parse(name, input);
  output = std::stoi(input);
}

void parse(std::string name, std::pair<std::vector<int>, std::vector<int>>& output) {
  std::string input;
  parse(name, input);
  std::regex numbersRegex("\\d+");
  auto it = std::sregex_iterator(input.begin(), input.end(), numbersRegex);
  while (it != std::sregex_iterator()) {
    output.first.push_back(std::stoi(it++->str()));
    output.second.push_back(std::stoi(it++->str()));
  }
}

void parse(std::string name, std::vector<std::vector<int>>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::regex numberRegex("-*\\d+");
  std::string line;
  while (std::getline(ss, line, '\n')) {
    std::vector<int> subOutput;
    auto it = std::sregex_iterator(line.begin(), line.end(), numberRegex);
    while (it != std::sregex_iterator()) {
      subOutput.push_back(std::stoi(it++->str()));
    }
    output.push_back(subOutput);
  }
}

void parse(std::string name, std::vector<int>& output) {
  std::string input;
  parse(name, input);
  for (const auto& ch : input) {
    output.push_back(ch - '0');
  }
}

void parse(std::string name, std::list<size_t>& output) {
  std::string input;
  parse(name, input);
  std::regex numberRegex("\\d+");
  auto it = std::sregex_iterator(input.begin(), input.end(), numberRegex);
  while (it != std::sregex_iterator()) {
    output.push_back(std::stoull(it++->str()));
  }
}

void parse(std::string name, std::vector<int64_t>& output) {
  std::string input;
  parse(name, input);
  std::regex numberRegex("\\d+");
  auto it = std::sregex_iterator(input.begin(), input.end(), numberRegex);
  while (it != std::sregex_iterator()) {
    output.push_back(std::stoi(it++->str()));
  }
}

void parse(std::string name, std::vector<std::vector<size_t>>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::regex numberRegex("\\d+");
  std::string line;
  while (std::getline(ss, line, '\n')) {
    std::vector<size_t> subOutput;
    auto it = std::sregex_iterator(line.begin(), line.end(), numberRegex);
    while (it != std::sregex_iterator()) {
      subOutput.push_back(std::stoull(it++->str()));
    }
    output.push_back(subOutput);
  }
}

void parse(std::string name, std::vector<std::vector<char>>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::string line;
  while (std::getline(ss, line, '\n')) {
    std::vector<char> subOutput;
    for (const auto& ch : line) {
      subOutput.push_back(ch);
    }
    output.push_back(subOutput);
  }
}

void parse(std::string name, std::vector<std::string>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::string line;
  while (std::getline(ss, line, '\n')) {
    output.push_back(line);
  }
}

void parse(std::string name, std::vector<std::pair<char, int>>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::string line;
  std::regex lineRegex("([LR])(\\d+)");
  while (std::getline(ss, line, '\n')) {
    std::smatch match;
    if (std::regex_match(line, match, lineRegex)) {
      char direction = match[1].str()[0];
      int distance = std::stoi(match[2].str());
      output.push_back({direction, distance});
    }
  }
}

void parse(std::string name, std::vector<std::pair<int64_t, int64_t>>& output) {
  std::string input;
  parse(name, input);
  std::regex regex("(\\d+)-(\\d+)");
  auto it = std::sregex_iterator(input.begin(), input.end(), regex);
  while (it != std::sregex_iterator()) {
    int64_t first = std::stoll((*it)[1].str());
    int64_t second = std::stoll((*it)[2].str());
    output.push_back({first, second});
    ++it;
  }
}

void parse(std::string name, std::pair<std::vector<std::pair<int64_t, int64_t>>, std::vector<int64_t>>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::string line;
  bool parsingFirstBlock = true;
  std::regex pairRegex("(\\d+)-(\\d+)");
  while (std::getline(ss, line, '\n')) {
    if (line.empty()) {
      parsingFirstBlock = false;
      continue;
    }
    if (parsingFirstBlock) {
      std::smatch match;
      if (std::regex_match(line, match, pairRegex)) {
        int64_t first = std::stoll(match[1].str());
        int64_t second = std::stoll(match[2].str());
        output.first.push_back({first, second});
      }
    } else {
      std::stringstream lineStream(line);
      std::string numberStr;
      while (std::getline(lineStream, numberStr, ',')) {
        output.second.push_back(std::stoll(numberStr));
      }
    }
  }
}

void parse(std::string name, std::vector<Position3D>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::string line;
  std::regex lineRegex("(-*\\d+),(-*\\d+),(-*\\d+)");
  while (std::getline(ss, line, '\n')) {
    std::smatch match;
    if (std::regex_match(line, match, lineRegex)) {
      long double x = std::stold(match[1].str());
      long double y = std::stold(match[2].str());
      long double z = std::stold(match[3].str());
      output.push_back(Position3D{x, y, z});
    }
  }
}

void parse(std::string name, std::vector<Position>& output) {
  std::string input;
  parse(name, input);
  std::stringstream ss(input);
  std::string line;
  std::regex lineRegex("(-*\\d+),(-*\\d+)");
  while (std::getline(ss, line, '\n')) {
    std::smatch match;
    if (std::regex_match(line, match, lineRegex)) {
      int x = std::stoi(match[1].str());
      int y = std::stoi(match[2].str());
      output.push_back(Position{x, y});
    }
  }
}