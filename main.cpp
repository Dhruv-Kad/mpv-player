#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
int main() {
  std::string line;
  bool collect = false;
  std::string extension;
  int number = 0;
  std::string valid_types[59] = {
      ".mkv",  ".mk3d", ".mka", ".mks",  ".mp4",  ".m4v",  ".mov",
      ".avi",  ".webm", ".ogm", ".mpg",  ".mpeg", ".ts",   ".m2ts",
      ".rm",   ".rmvb", ".wmv", ".asf",  ".flv",  ".f4v",  ".3gp",
      ".nut",  ".bik",  ".dv",  ".bdmv", ".mpls",

      ".mp3",  ".aac",  ".m4a", ".flac", ".wav",  ".opus", ".ogg",
      ".alac", ".dts",  ".ac3", ".wma",  ".amr",  ".spx",  ".mpc",
      ".ape",  ".ra",   ".shn", ".imc",

      ".srt",  ".ass",  ".ssa", ".sub",  ".rt",   ".smi",  ".idx",
      ".pjs",  ".jss",  ".aqt", ".vtt",  ".ttml", ".dvb",  ".ttxt",
  };

  std::vector<std::string> avalfiles;
  // Get all files in the thing
  std::system("ls -h >test.txt");
  std::ifstream streamer("test.txt");
  // Find compatiable files and add to list
  while (std::getline(streamer, line)) {
    // Gets extension of file
    collect = false;
    extension = "";
    for (char m : line) {
      if (m == '.') {
        collect = true;
      }
      if (collect) {
        extension += m;
      }
    }
    for (std::string m : valid_types) {
      if (m == extension) {
        number++;
        std::cout << "[" << number << "]. " << line << "\n";
        avalfiles.push_back(line);
        break;
      }
    }
  }
  system("rm test.txt");
  streamer.close();
  std::cout << "Enter a choice to play (0 to quit): ";
  std::cin >> number;
  number--;
  if (number >= 0 && number < avalfiles.size()) {
    line = avalfiles[number];
    extension = "mpv \'" + line + "\'";
    std::system(extension.c_str());
  }
}
