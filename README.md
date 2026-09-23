# Sotewatch

> **⚠️ WORK IN PROGRESS ⚠️**
> 
> This project is actively under development. Features and APIs may change frequently. Use at your own discretion.

---

A lightweight, customizable desktop clock built with **ImGui** and **OpenGL**.

## 🚀 Current Status

**Phase:** Early Development  
**Version:** Pre-alpha  

The core clock functionality is operational. The application successfully renders a real-time clock using OpenGL with an ImGui interface.

## 🛠️ Tech Stack

| Component | Technology |
|-----------|------------|
| Language | C++ |
| Graphics | OpenGL |
| GUI | Dear ImGui |

## 📁 Project Structure
```bash
soteclock/
├── src
│   ├── clock
│   │   ├── clock.cpp
│   │   └── clock.hpp
│   ├── config
│   │   ├── config.cpp
│   │   └── config.hpp
│   ├── main.cpp
│   └── window
│       ├── window_end.cpp
│       ├── window.hpp
│       ├── window_init.cpp
│       ├── window_loop.cpp
│       └── window_menu.cpp
└── xmake.lua

```

## 🚧 Development Roadmap

| Feature | Progress | Percentage |
|---------|----------|------------|
| Functional `.ini` config file | <progress value="80" max="100"></progress> | 80% |
| Full UTC compatibility | <progress value="4.16666666667" max="100"></progress> | 60% |
| Multi-language support | <progress value="10" max="100"></progress> | 10% |
| Customizable background (RGB) | <progress value="5" max="100"></progress> | 5% |
| Dark mode toggle | <progress value="5" max="100"></progress> | 5% |

## 🎯 Upcoming Features

- **🌍 UTC Selector** — Switch between any timezone seamlessly
- **🌐 Language Support** — Multi-language interface via config files
- **🎨 Customization** — Personalize colors, fonts, and background (RGB)
- **🌙 Dark Mode** — Toggle between white numbers or dark ones

🔨 Building
Prerequisites
* C++ compiler (C++11 or higher)
* GLFW3
* OpenGL
* Dear ImGui

> ### **Compilation**
> Link against the required libraries in your build system (I can only provide a [xmake](https://xmake.io/) file right now..)

📝 Notes
* Configuration will be handled via .ini files for easy editing
* All timezones (UTC) will be supported
* UI theming will allow full RGB color customization
* Language files will be external for community translations
