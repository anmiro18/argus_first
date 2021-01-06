#pragma once
#include <opencv2/core.hpp>
#include <string>
#include <unordered_map>

namespace core {

class Core {
public:
  void loadImage(std::string const& key, std::string const& path);
  void saveImage(std::string const& key, std::string const& path);

  void blur(std::string const& key, std::string const& newKey, int size);

  void resize(std::string const& key, std::string const& newKey,
              std::size_t newWidth, std::size_t newHeight);

private:
  bool checkKeyInImage(std::string const& key);
  bool checkKeyNotInImage(std::string const& key);
  bool checkExtensionFile(std::string const& filePath);

private:
  std::unordered_map<std::string, cv::Mat> images;
};

} // namespace core
