# zgame-demo

A game written in C++ for the [WASM-4](https://wasm4.org) fantasy console.

This is a public version of the game originally gifted to my wife, celebrating her 30th birthday, and 10 years together.
The "gameplay" consists of scenes from the past 10 years, including messages from friends and family, a very light puzzle element, and collecting hidden items and hidden screens.

This public version has all personal messages from family and friends stripped out of git history and replaced simply with "Happy Birthday"

## Building

Build the cart by running:

```shell
make
```

Then run it with:

```shell
w4 run build/cart.wasm
```

For more info about setting up WASM-4, see the [quickstart guide](https://wasm4.org/docs/getting-started/setup?code-lang=cpp#quickstart).
