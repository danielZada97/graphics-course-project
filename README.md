# 🛝 Interactive 3D Playground in OpenGL

### 🎮 A First-Person Digital Playground Simulation Built in C with OpenGL

This project is a fully interactive 3D playground, designed using **C** and the **OpenGL** graphics API, along with the **GLUT** utility toolkit. The simulation features animated playground equipment, textured environments, characters, and a first-person navigation system. It was created as part of an academic course and received the **highest grade in class (100)**.

---

## 🧠 About the Technology

### C Programming Language
The simulation is written in **C**, a powerful low-level programming language known for its performance and control over system-level operations. C is commonly used in graphics, embedded systems, and game engines.

### OpenGL & GLUT
- **OpenGL** (Open Graphics Library) is a cross-platform graphics API used for rendering 2D and 3D vector graphics.
- **GLUT** (OpenGL Utility Toolkit) provides windowing and input control, making it easier to build OpenGL-based applications.

Together, they enable real-time rendering and keyboard interaction in the 3D playground.

---

## 🖼️ Textures & Assets

The project uses **BMP images** for applying realistic textures to objects like grass, brick walls, wood, skyboxes, and more. These textures are loaded at runtime and mapped to geometric primitives to simulate a visually engaging environment.

Make sure the following `.bmp` files are in the working directory:
- `sky3.bmp`, `brick.bmp`, `grass1.bmp`, `sun.bmp`, `moon.bmp`, `nametag.bmp`, and many others (see full list in `main.c`)

---

## ✨ Features

- ✅ First-person movement with keyboard controls
- ✅ Real-time day/night cycle and lighting effects
- ✅ Animated seesaws, swings, characters, and carousels
- ✅ Multiple camera angles and zoom
- ✅ Right-click context menu for toggling lights, textures, and animations
- ✅ Textured 3D objects with realistic materials

---

## 🎮 Controls

| Key         | Action                            |
|-------------|-----------------------------------|
| `W` / `S`   | Move forward/backward             |
| `A` / `D`   | Move left/right                   |
| `Q` / `E`   | Move up/down                      |
| `I` / `K`   | Move character forward/backward   |
| `J` / `L`   | Move character left/right         |
| `[`         | Toggle first-person view mode     |
| `+` / `-`   | Zoom in/out (adjust FOV)          |
| `Arrow Keys`| Rotate camera angle               |
| `1–4`       | Switch between view modes         |
| `.`         | Toggle textures                   |
| `Esc`       | Exit the program                  |

Right-click to open the in-game menu for controlling:
- Lights (1–5 or all)
- Textures (on/off)
- Day/Night mode and cycle
- Animations (on/off)
- Reset or Exit
![image](https://github.com/user-attachments/assets/252c9ff1-a759-49e6-8521-c04340f48650)




![Playground Demo](./screenshot.png)
