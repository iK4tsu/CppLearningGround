# C++ learning ground
These projects are part of a C++ professional development program. Some
solutions might not be ideal nor pratical.

## Project organization
Each exercise is stored in the **subprojects** directory. This is just a simple
way to handle multiple projects with Meson giving me the ability to compile each
one independently.

*This might not be the best solution to achieve this with Meson*.

## Setup
With Meson:
```sh
meson setup builddir
ninja -C builddir
```

This will create the environment and build all the projects located in the
**subprojects** directory.

### Build
To build a single subproject you just have to pass the folder name of any
project located in **subprojects** (e.g ex6.2).
```sh
ninja -C builddir ex6.2
```

### Run
Running is pretty simple, just execute the runnable inside **builddir**
following the same path of the project's structure (e.g ex6.2).
```
./builddir/subprojects/ex6.2/ex6.2
```

### Manually build
If you do not have the ability to do this with Meson you can build each project
manually using your prefered compiler. Just make sure your compiler can support
the `c++20` features used in some exercices.

## Dependencies
* [Range-V3](https://ericniebler.github.io/range-v3/)
