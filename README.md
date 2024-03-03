# zgame-demo

A game written in C++ for the [WASM-4](https://wasm4.org) fantasy console.

This is an anonymised* version of an 8-bit style game made for my wife.
The gameplay consists of 9 scenes from the past 10 years, including messages from friends and family, a very light puzzle element, and collecting hidden items and hidden screens.

*This public version has all personal messages from family and friends replaced and stripped out of git history.

![](https://github.com/peteranastasiou/zgame-demo/blob/master/demo1.gif)


![](https://github.com/peteranastasiou/zgame-demo/blob/master/demo2.gif)


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
