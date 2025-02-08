# Forgotten World - MMO RPG

## Setup Instructions for Linux

To build and run *Forgotten World* on a Linux system, you need to install the following dependencies.

### **1. Install Required Packages**
Run the following command to install all necessary dependencies:

```bash
sudo apt update && sudo apt install -y \
    cmake \
    g++ \
    libsfml-dev \
    libenet-dev \
    liblua5.4-dev \
    libxrandr-dev \
    libudev-dev \
    libfreetype6-dev \
    libopenal-dev \
    libflac-dev \
    libvorbis-dev \
    libx11-dev \
    libxext-dev \
    libxrender-dev \
    git-lfs
```

### **2. Clone the Repository**
Make sure you have `git-lfs` installed before cloning:

```bash
git lfs install  # Initialize Git LFS
git clone [your-repo-url]  # Clone the repository
cd Forgotten-World
```

### **3. Pull LFS Files**
If assets are stored using Git LFS, run:

```bash
git lfs pull
```

### **4. Build the Project**

```bash
mkdir -p build && cd build
cmake ..
make -j$(nproc)
```

### **5. Run the Game**

```bash
./Forgotten_World
```

### **Troubleshooting**
- If you get errors related to missing SFML libraries, ensure `libsfml-dev` is installed.
- If textures are not loading, verify that `git lfs pull` has been run.
- If ENet is not found, check `libenet-dev` is installed.

Enjoy the game! 🚀

