#include <iostream>
#include <filesystem>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cout << "Usage:" << argv[0] << "<path> \n";
    return EXIT_FAILURE;
  }

  std::filesystem::path p{argv[1]};
  if (is_regular_file(p))
  {
    std::cout << p << "exist with" << file_size(p) << "bytes \n";
  }
  else if (is_directory(p))
  {
    std::cout << p << " is a directory containing \n";
    for (auto &e : std::filesystem::directory_iterator{p})
    {
      std::cout << " " << e.path() << " \n";
    }
  }
  else if (exists(p))
  {
    std::cout << p << " is a special folder\n";
  }
  else
  {
    std::cout << "path " << p << " does not exists\n";
  }
}