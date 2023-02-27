# fdf
This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).

![alt text](https://github.com/philippschwarzmueller/fdf/blob/master/test_maps/fdf_showcase.jpg "fdf showcase")

## how it works
1. When running the program you pass it a path to a .fdf file
2. The file will be parsed into an array of coordinates
3. Iterating the array the coordinates are calculated to be projected in an isometric manner
4. The pixels are being placed according to the coordinates
5. Keyhooks track the keypresses and let the program respond accordingly
6. On close (closing window or SIG_INT) memoryallocations are freed and the program exits

## how to use
(if not installed you will need to install glfw - very easy with brew for example)
1. Clone the repo
2. Run make
3. `./fdf /test_maps/42.fdf`
