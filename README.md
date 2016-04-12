# OpenGL Rasterizer

## Overview
This program uses the OpenGL pipeline to render an object represented as a triangle mesh. The actual object is composed of ~69,000 triangles. 

## Running
1. open `PA3.xcodeproj`.
2. Go to `Product` -> `Scheme` -> `Edit Scheme` -> `Options`
3. Make sure that the working directory is correct
4. To run part 1, choose the `Immediate` scheme under `Product` -> `Scheme` 
5. To run part 2, choose the `VAO` scheme under `Product` -> `Scheme` 
6. click the run button

## Performance
- Immediate mode: ~237FPS
- Vertex Arrays: ~760FPS

## Result
<img src="/out/bunny.png" width="400px" height="400px" />