#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

namespace fs = std::filesystem;
using namespace std;

class FileClassifier {
public:
    string classify(const fs::path& file) {
        string ext = file.extension().string();
        transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

        if (ext == ".jpg" || ext == ".png" || ext == ".jpeg" || ext == ".gif" || ext == ".webp") {
            return "Images";
        }
        else if (ext == ".pdf" || ext == ".docx" || ext == ".txt" || ext == ".pptx" || ext == ".xlsx") {
            return "Documents";
        }
        else if (ext == ".mp4" || ext == ".mkv" || ext == ".mov" || ext == ".avi") {
            return "Videos";
        }
        else if (ext == ".mp3" || ext == ".wav" || ext == ".flac" || ext == ".aac" || ext == ".ogg" || ext == ".m4a" || ext == ".opus") {
            return "Audios";
        }
        else if (ext == ".zip" || ext == ".rar" || ext == ".7z" || ext == ".tar") {
            return "Archives";
        }
        else {
            return "Others";
        }
    }
};

class FileScanner {
public:
    vector<fs::path> scan(const string& folderPath) {
        vector<fs::path> files;

        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (fs::is_regular_file(entry)) {
                files.push_back(entry.path());
            }
        }
        return files;
    }
};

class FileMover {
public:
    void move(const fs::path& file, const fs::path& basePath, const string& category) {
        fs::path targetDir = basePath / category;

        if (!fs::exists(targetDir)) {
            fs::create_directories(targetDir);
        }

        fs::path targetPath = targetDir / file.filename();

        try {
            fs::rename(file, targetPath);
        } catch (const exception& e) {
            cout << "Failed to move: " << file << "\n" << e.what() << endl;
        }
    }
};

class FileOrganizer {
private:
    FileMover mover;
    FileScanner scanner;
    FileClassifier classifier;

    fs::path folderPath;

public:
    FileOrganizer(const fs::path& path) : folderPath(path) {}

    void organize() {
        vector<fs::path> files = scanner.scan(folderPath.string());
        cout << "Organizing: " << folderPath << endl;

        for (const auto& file : files) {
            string category = classifier.classify(file);
            mover.move(file, folderPath, category);
            cout << "Moved: " << file.filename() << " -> " << category << endl;
        }
        cout << "Done organizing!" << endl;
    }
};

int main() {
    int choice;

    cout << "File Organizer\n";
    cout << "Pick the directory you want to organize\n";
    cout << "1. Desktop\n";
    cout << "2. Downloads\n";
    cout << "3. Documents\n";
    cout << "Choose an option: ";
    cin >> choice;

    const char* envVar;
    #ifdef _WIN32
        envVar = getenv("USERPROFILE");
    #else
        envVar = getenv("HOME");
    #endif

    if (!envVar) {
        cout << "Could not determine home directory." << endl;
        return 1;
    }

    fs::path basePath(envVar);

    if (choice == 1) basePath /= "Desktop";
    else if (choice == 2) basePath /= "Downloads";
    else if (choice == 3) basePath /= "Documents";
    else {
        cout << "Invalid choice" << endl;
        return 1;
    }

    FileOrganizer app(basePath);
    app.organize();

    return 0;
}