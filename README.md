# 🎵 Groovebox

<br>

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-CLI-black?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Stable-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-lightgrey?style=for-the-badge)

**Groovebox** is a terminal-based music playlist manager. Add tracks, play your playlist, search by title, and view listening statistics from the command line.

---

## 📋 Features

- **Add tracks** — create new tracks with title, artist, duration, release year, and availability status
- **Play playlist** — simulate playback with automatic play count tracking
- **Search tracks** — find tracks by title using substring matching
- **Toggle availability** — mark tracks as available or upcoming
- **View statistics** — see total duration, average duration, and most played track
- **Remove last track** — delete the most recently added track
- **Input validation** — handles wrong input without crashing

---

## 🚀 Getting Started

### Requirements

- A C++ compiler supporting C++11 or later (`g++`, `clang++`, MSVC)

### Compile

```bash
g++ -std=c++17 -o groovebox groovebox.cpp
```

### Run
```bash
./groovebox      # Linux / macOS
groovebox.exe    # Windows
```

---

## ⚙️ How It Works

The system manages a playlist of up to 5 tracks with the following metadata:
- Title
- Artist
- Duration (30–600 seconds)
- Release year (1700–2026 for available tracks, 2026+ for upcoming tracks)
- Availability status
- Play count (automatically incremented when played)
Data is stored in parallel arrays (one per field: title, artist, duration, year, streams, availability) and a counter tracks how many tracks are currently in the playlist.
When a track is played, the play count increments automatically. The statistics option calculates total duration, average duration, and identifies the most played track.

## 🖥️ Example Session

```text
------ Groovebox ------
1. Add track to playlist
2. Play playlist
3. Search track by title
4. Toggle track availability
5. Playlist statistics
6. Remove last track
7. Exit

Select an option: 1

--- Track 1 ---
Title: Everlong
Artist: Foo Fighters
Duration (30-600 s): 250
Available (yes/no): yes
Release year: 1997
Track added successfully!

Select an option: 2

--- PLAYING PLAYLIST ---
1. Everlong - Foo Fighters (250 s) [1997]

Select an option: 7

Thank you for using Groovebox!
```

## 👥 Team

- **Flavio Lanzafame** — [@flaviolanzafame](https://github.com/flaviolanzafame)
- **Christian Peritore** — [@ChristianPeritore](https://github.com/ChristianPeritore)
- **Wassim Marfoq** — [@WassimAuraFarmer](https://github.com/WassimAuraFarmer/)

> School project — ITET M. Rapisardi - L. da Vinci · Computer Science & Telecommunications, Computer Science specialization · Year 3 (2026)

---

## 📄 License

Released under the [MIT License](LICENSE).

---

<div align="center">

Built with C++ · and TonyPitony in the <3

</div>
