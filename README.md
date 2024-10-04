# **Cub3D**

## **Overview**

**Cub3D** is a 42 project that challenges students to create a 3D maze-like game using a technique called **raycasting**. Inspired by classic games like **Wolfenstein 3D**, Cub3D offers a first-person perspective where the player explores a 2D maze that is rendered to look 3D. The player navigates through the maze, interacting with walls and other elements in the environment.

The project emphasizes **understanding computer graphics**, **mathematics**, and **game engine development**.

---

## **Raycasting**

**Raycasting** is the key rendering technique in Cub3D that simulates a 3D world from a 2D map. It works by projecting rays from the player’s point of view and calculating where these rays intersect with walls in the 2D grid, allowing the game to create the illusion of depth and perspective.

### **How Raycasting Works:**
1. **Ray Projection:** For each vertical stripe of the screen, a ray is cast from the player’s position, traveling in a specific direction based on the player's orientation.
2. **Wall Detection:** The ray moves through the map grid, checking for intersections with walls. When a ray hits a wall, the distance to the wall is calculated.
3. **Distance Correction:** The distance is adjusted to prevent distortion (called "fish-eye" effect) by taking the angle of the ray into account.
4. **Wall Rendering:** Using the corrected distance, the height of the wall on the screen is calculated. Closer walls are drawn taller, and farther walls are drawn shorter, simulating depth.
5. **Texture Mapping (Optional):** Textures can be applied to walls to enhance realism. Each ray determines which part of the wall texture should be displayed based on where the ray strikes.

### **Advantages of Raycasting:**
- **Efficient:** Raycasting is computationally less expensive than full 3D rendering, making it ideal for simple 3D-like games.
- **Fast:** It only renders the objects visible to the player, optimizing performance.
- **Simpler math:** Since it primarily works in 2D space, raycasting avoids the complexity of 3D geometry, while still producing a 3D visual effect.

---

## **Features**

- **First-Person View:** Explore a maze from the player's perspective.
- **Real-time Rendering:** Raycasting algorithm is used to dynamically render the environment based on player movement and orientation.
- **2D Map Representation:** The game world is represented as a 2D grid of walls and empty spaces.
- **Wall Texturing:** Optional textures can be applied to the walls for a more immersive experience.

---

## **Getting Started**

### **Requirements**
- **MinilibX**: This project requires MinilibX for window management and graphics.
- **Make**: The build system is managed with a `Makefile`.

### **Compilation**

To compile the project, run:

```bash
make
```
