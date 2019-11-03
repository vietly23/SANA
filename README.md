# SANA

## Compile & Run

- Run command `./make-distribution`
- Go to the `build` directory
- Run `make` 

## Testing

To run the unit tests, do the following:

- Run command `./make-distribution`
- Go to the `build` directory
- Run `make test`

### Memory Leakage 

For a sanity check, please run `valgrind ./build/bin/test-lib-sana`. Valgrind *should* catch any egregious
memory leaks.


## Contributions
To contribute to this project, please make sure to adhere to the
[Google C++ style guide](https://google.github.io/styleguide/cppguide.html). If you're unsure that it follows the
Style Guide, you can use Google's cpplint in their [styleguide repo](https://github.com/google/styleguide).
