#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> headers = {"<fstream>", "<iostream>", "<string>", "<vector>"};

std::string main_source =
    "int main() {\n"
    "  using std::endl;\n"
    "\n"
    "  std::ofstream out_file;\n"
    "  out_file.open(\"quine-output.cc\");\n"
    "\n"
    "  // Include headers.\n"
    "  for (auto header : headers) {\n"
    "    out_file << \"#include \" << header << endl;\n"
    "  }\n"
    "  out_file << endl;\n"
    "\n"
    "  // Define vector of headers.\n"
    "  out_file << \"std::vector<std::string> headers = {\";\n"
    "  for (int i = 0; i < headers.size(); ++i) {\n"
    "    if (i != headers.size() - 1) {\n"
    "      out_file << \"\\\"\" << headers[i] << \"\\\", \";\n"
    "    } else {\n"
    "      out_file << \"\\\"\" << headers[i] << \"\\\"\";\n"
    "    }\n"
    "  }\n"
    "  out_file << \"};\" << endl << endl;\n"
    "\n"
    "  // Define main_source string.\n"
    "  out_file << \"std::string main_source =\" << endl;\n"
    "  for (int i = 0; i < main_source.size(); ++i) {\n"
    "    out_file << \"    \\\"\";\n"
    "    for (; i < main_source.size(); ++i) {\n"
    "      char c = main_source[i];\n"
    "      switch (c) {\n"
    "        case '\\n':\n"
    "          out_file << \"\\\\n\";\n"
    "          break;\n"
    "        case '\\\\':\n"
    "          out_file << \"\\\\\\\\\";\n"
    "          break;\n"
    "        case '\\\"':\n"
    "          out_file << \"\\\\\\\"\";\n"
    "          break;\n"
    "        default:\n"
    "          out_file << c;\n"
    "          break;\n"
    "      }\n"
    "      if (c == '\\n') {\n"
    "        out_file << \"\\\"\" << endl;\n"
    "        break;\n"
    "      }\n"
    "    }\n"
    "  }\n"
    "  out_file << \"\\\";\" << endl << endl;\n"
    "\n"
    "  // Write main_source code\n"
    "  out_file << main_source << endl;\n"
    "\n"
    "  out_file.close();\n"
    "}";

int main() {
  using std::endl;

  std::ofstream out_file;
  out_file.open("quine-output.cc");

  // Include headers.
  for (auto header : headers) {
    out_file << "#include " << header << endl;
  }
  out_file << endl;

  // Define vector of headers.
  out_file << "std::vector<std::string> headers = {";
  for (int i = 0; i < headers.size(); ++i) {
    if (i != headers.size() - 1) {
      out_file << "\"" << headers[i] << "\", ";
    } else {
      out_file << "\"" << headers[i] << "\"";
    }
  }
  out_file << "};" << endl << endl;

  // Define main_source string.
  out_file << "std::string main_source =" << endl;
  for (int i = 0; i < main_source.size(); ++i) {
    out_file << "    \"";
    for (; i < main_source.size(); ++i) {
      char c = main_source[i];
      switch (c) {
        case '\n':
          out_file << "\\n";
          break;
        case '\\':
          out_file << "\\\\";
          break;
        case '\"':
          out_file << "\\\"";
          break;
        default:
          out_file << c;
          break;
      }
      if (c == '\n') {
        out_file << "\"" << endl;
        break;
      }
    }
  }
  out_file << "\";" << endl << endl;

  // Write main_source code
  out_file << main_source << endl;

  out_file.close();
}
