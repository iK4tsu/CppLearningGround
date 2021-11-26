# Execution policy: parallel
Parallelism is wonderfull for speeding a projects, but should it be blindly used?

## Build and run
This is prepared with meson to make your life easier. If you have meson installed run:
```bash
$ meson setup builddir
$ ninja -C builddir
```

You must compile with `gcc`. Make sure `gcc` is your default compiler.

You're all set!\
To run the executable: `./builddir/execution-policy`

# Dependencies
[TBB](https://github.com/oneapi-src/oneTBB)
