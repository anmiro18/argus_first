#include "core.h"

#include <iostream>
#include <vector>

#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

namespace core {

void Core::loadImage(const std::string& key, const std::string& path) {
  if (!checkKeyNotInImage(key) || !checkExtensionFile(path)) {
    return;
  }
  std::string image_path = cv::samples::findFile(path);
  cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
  if (img.empty()) {
    std::cout << "Could not read the image: " << image_path << std::endl;
    return;
  }

  images[key] = img;
}

void Core::saveImage(const std::string& key, const std::string& path) {
  if (!checkKeyInImage(key) || !checkExtensionFile(path)) {
    return;
  }
  imwrite(path, images.at(key));
}

void Core::blur(const std::string& key, const std::string& newKey, int size) {
  if (!checkKeyInImage(key)) {
    std::cout << "Could not find image with name: " << key;
  }

  if (!checkKeyNotInImage(newKey)) {
    return;
  }

  images[newKey] = images.at(key);
  cv::blur(images.at(key), images.at(newKey), cv::Size(size, size));
}

void Core::resize(const std::string& key, const std::string& newKey,
                  std::size_t newWidth, std::size_t newHeight) {

  if (!checkKeyInImage(key)) {
    std::cout << "Could not find image with name: " << key;
  }

  if (!checkKeyNotInImage(newKey)) {
    return;
  }

  images[newKey] = images.at(key);

  cv::resize(images.at(key), images.at(newKey), cv::Size(newHeight, newWidth));
}

bool Core::checkKeyInImage(const std::string& key) {

  if (images.find(key) == images.end()) {
    std::cout << "Could not find image with name: " << key;
    return false;
  }

  return true;
}

bool Core::checkKeyNotInImage(const std::string& key) {
  if (images.find(key) != images.end()) {
    std::cout << "Name of image : " << key << " already exist";
    return false;
  }

  return true;
}

bool Core::checkExtensionFile(const std::string& filePath) {
  const std::vector<std::string> extensions = {".jpg", ".jpeg"};
  for (const auto& extension : extensions) {
    auto pos = filePath.find(extension);
    if (pos == filePath.size() - extension.size()) {
      return true;
    }
  }
  std::cout << "file extension is not supported " << filePath;
  return false;
}

} // namespace core
