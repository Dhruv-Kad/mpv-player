#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::string valid_types[58] = {
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
void sanitized_select() {
  std::string line;
  std::string extension;
  int number = 0;
  bool collect = false;
  std::vector<std::string> avalfiles;
  // Get all files in the thing
  // Honestly, we don't even need to do this, we can just make it so only valids
  // get ls'd
  for (std::string m : valid_types) {
    extension = "ls *";
    extension += m;
    extension += " >> validFilesList.txt 2>/dev/null";
    std::system(extension.c_str());
  }
  std::ifstream streamer("validFilesList.txt");
  // Find compatiable files and add to list
  while (std::getline(streamer, line)) {
    number++;
    std::cout << "[" << number << "]. " << line << "\n";
    avalfiles.push_back(line);
  }
  streamer.close();
  std::cout << "Enter a choice to play (0 to quit): ";
  std::cin >> number;
  number--;
  if (number >= 0 && number < avalfiles.size()) {
    line = avalfiles[number];
    extension = "mpv \'" + line + "\' &";
    std::system(extension.c_str());
  }
  system("rm validFilesList.txt");
}
int main() {
  sanitized_select();
  // other options tba
}
