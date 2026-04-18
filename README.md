# 🗂️ Sortify — File Organizer

> A lightweight, cross-platform C++ CLI tool that automatically sorts files in a directory into categorized subfolders by file type.

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat-square&logo=c%2B%2B)
![License](https://img.shields.io/badge/license-MIT-green?style=flat-square)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=flat-square)
![Status](https://img.shields.io/badge/status-active-brightgreen?style=flat-square)

---

## 📖 Overview

**Sortify** scans a chosen directory and moves files into organized subfolders based on their extensions — no manual sorting required. It supports common images, documents, videos, audio, archives, and code files, placing anything unrecognized into an `Others/` folder.

---

## ✨ Features

- 📁 Automatically categorizes files by extension
- 🖥️ Cross-platform — works on Windows, Linux, and macOS
- ⚡ Fast scan using `std::filesystem` (C++17)
- 🛡️ Safe error handling — failed moves are reported without crashing
- 🧩 Clean OOP architecture (`FileScanner`, `FileClassifier`, `FileMover`, `FileOrganizer`)

### 🔜 Planned Features (Coming Soon)
- 🔍 **Dry-run mode** — preview changes before committing
- 🔁 **Collision handling** — auto-rename duplicates instead of overwriting
- 📝 **Custom path support** — organize any directory, not just system folders
- 📊 **Summary report** — see a count of files moved per category
- 🧩 **Plugin-style extension map** — add new file types via config file

---

## 📂 Output Structure

After running Sortify on a directory, files are organized like this:

```
Downloads/
├── Images/
│   ├── photo.jpg
│   └── banner.png
├── Documents/
│   ├── resume.pdf
│   └── notes.txt
├── Videos/
│   └── tutorial.mp4
├── Audios/
│   └── podcast.mp3
├── Archives/
│   └── project.zip
├── Code/
│   └── main.cpp
└── Others/
    └── unknownfile.xyz
```

---

## 🚀 Getting Started

### Prerequisites

- A C++17-compatible compiler:
  - **GCC** 8+ (`g++`)
  - **Clang** 7+
  - **MSVC** 2017+
- `std::filesystem` support (included in C++17 standard library)

### Build

```bash
# Clone the repository
git clone https://github.com/OsmondJnr/sortify.git
cd sortify

# Compile with g++
g++ -std=c++17 -o sortify File_Organizer.cpp

# On Windows (MinGW)
g++ -std=c++17 -o sortify.exe File_Organizer.cpp
```

### Run

```bash
# Linux / macOS
./sortify

# Windows
sortify.exe
```

You'll be prompted to pick a directory:

```
== File Organizer ==
1. Desktop
2. Downloads
3. Documents
4. Enter custom path
Choice:
```

---

## 🗃️ Supported File Types

| Category   | Extensions                                      |
|------------|-------------------------------------------------|
| Images     | `.jpg` `.jpeg` `.png` `.gif` `.webp`            |
| Documents  | `.pdf` `.docx` `.txt` `.xlsx` `.pptx`           |
| Videos     | `.mp4` `.mkv` `.mov` `.avi`                     |
| Audios     | `.mp3` `.wav` `.flac` `.aac`                    |
| Archives   | `.zip` `.rar` `.7z` `.tar`                      |
| Others     | Anything not listed above                       |

---

## 🏗️ Architecture

```
FileOrganizer        ← Orchestrates the full workflow
├── FileScanner      ← Scans directory, returns list of file paths
├── FileClassifier   ← Maps file extensions to category names
└── FileMover        ← Creates target directories and moves files
```

Each class has a single responsibility, making the codebase easy to extend and test.

---

## 🤝 Contributing

Contributions are welcome! Here's how to get started:

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/your-feature-name`
3. Commit your changes: `git commit -m "Add your feature"`
4. Push to your branch: `git push origin feature/your-feature-name`
5. Open a Pull Request

Please make sure your code compiles cleanly with `-std=c++17` and follows the existing class structure.

---

## 🐛 Reporting Issues

Found a bug or have a suggestion? [Open an issue](https://github.com/OsmondJnr/sortify/issues) and include:
- Your OS and compiler version
- Steps to reproduce the problem
- Any error output from the terminal

---

## 👤 Author

**Osmond** — [@OsmondJnr](https://github.com/OsmondJnr)  
Portfolio: [dev-osmond.vercel.app](https://dev-osmond.vercel.app)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.
