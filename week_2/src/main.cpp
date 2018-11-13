#include <iostream>
#include <experimental/filesystem>

int main (int argc, char** argv) {
    if (argc == 1) {
        std::cout << "error: no directory argument\n";
        return 1;
    }
    namespace fs = std::experimental::filesystem; // https://en.cppreference.com/w/cpp/experimental/fs

    try {
        fs::path backuped_dir (argv[1]); // https://en.cppreference.com/w/cpp/experimental/fs/path
        if (!fs::is_directory (argv[1])) { // https://en.cppreference.com/w/cpp/experimental/fs/is_directory
            std::cout << "error:" << argv[1] << " is not a directory\n";
            return 3;
        }
        fs::directory_iterator it (backuped_dir), end; // https://en.cppreference.com/w/cpp/experimental/fs/directory_iterator/directory_iterator
        // Сконструированный по умолчанию directory_iterator "указывает" на пост-последний объект в директории
        while (it != end) {
            fs::directory_entry entry = *it; // https://en.cppreference.com/w/cpp/experimental/fs/directory_entry
            it++;
            fs::path entry_path = entry.path(); // https://en.cppreference.com/w/cpp/experimental/fs/directory_entry/path

            if (entry_path.extension() == ".txt") { // https://en.cppreference.com/w/cpp/experimental/fs/path/extension
                if (!fs::is_regular_file(entry_path)) { // https://en.cppreference.com/w/cpp/experimental/fs/is_regular_file
                    std::cout << "skip:" << entry_path << " is a directory\n";
                    continue;
                }
                fs::path copy_to(entry_path);
                copy_to.replace_extension(".txt.backup"); // https://en.cppreference.com/w/cpp/experimental/fs/path/replace_extension
                if (fs::exists(copy_to)) { // https://en.cppreference.com/w/cpp/experimental/fs/exists
                    std::cout << "skip:" << copy_to << " already exists" << "\n";
                    continue;
                }
                std::cout << "copy:" << entry_path << " to: " << copy_to << "\n";
                fs::copy_file(entry_path, copy_to); // https://en.cppreference.com/w/cpp/experimental/fs/copy_file
            }
        }

    } catch (fs::filesystem_error& error) { // https://en.cppreference.com/w/cpp/experimental/fs/filesystem_error
        std::cout << "error:" << error.what() << "\n";
        return 2;
    }
}
