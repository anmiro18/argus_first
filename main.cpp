#include <iostream>

#include "core.h"

int main(int argc, char* argv[]) {

  core::Core core;

  while (true) {
    std::string command;
    std::cin >> command;
    if (command == "load" || command == "ld") {
      std::string name;
      std::string filePath;
      std::cin >> name >> filePath;

      core.loadImage(name, filePath);
    } else if (command == "store" || command == "s") {
      std::string name;
      std::string filePath;
      std::cin >> name >> filePath;

      core.saveImage(name, filePath);
    } else if (command == "blur") {
      std::string fromName;
      std::string toName;
      std::size_t size;
      std::cin >> fromName >> toName >> size;

      core.blur(fromName, toName, size);
    } else if (command == "resize") {
      std::string fromName;
      std::string toName;
      std::size_t width;
      std::size_t height;
      std::cin >> fromName >> toName >> width >> height;

      core.resize(fromName, toName, width, height);
    } else if (command == "help" || command == "h") {
      std::cout << "Commands :\n";
      std::cout << "\t load, ld <name> <filePath> - load image to system\n";
      std::cout << "\t store, s <name> <filePath> - save image\n";
      std::cout << "\t blur <name> <newName> <size> - blur image\n";
      std::cout << "\t resize <name> <newName> <newWidth> <newHeigth> - resize "
                   "image\n";
      std::cout << "\t exit, quit, q - exit\n";
      std::cout << "files extension only jpg\n";
    } else if (command == "exit" || command == "quit" || command == "q") {
      break;
    } else {
      std::cout << "command not found " << command << '\n';
    }
  }

  return 0;
}
