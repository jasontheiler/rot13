# ROT13

```sh
$ hyperfine --shell none --warmup 100 --input ./test.txt ~/.cargo/bin/rot13 ~/.go/bin/rot13
Benchmark 1: ~/.cargo/bin/rot13
  Time (mean ± σ):     934.3 µs ±  51.4 µs    [User: 68.2 µs, System: 7.9 µs]
  Range (min … max):   855.5 µs … 1430.8 µs    3194 runs

  Warning: Statistical outliers were detected. Consider re-running this benchmark on a quiet system without any interferences from other programs. It might help to use the '--warmup' or '--prepare' options.

Benchmark 2: ~/.go/bin/rot13
  Time (mean ± σ):       1.4 ms ±   0.1 ms    [User: 0.6 ms, System: 0.0 ms]
  Range (min … max):     1.1 ms …   2.2 ms    2270 runs

  Warning: Statistical outliers were detected. Consider re-running this benchmark on a quiet system without any interferences from other programs. It might help to use the '--warmup' or '--prepare' options.

Summary
  /home/jason/.cargo/bin/rot13 ran
    1.51 ± 0.12 times faster than /home/jason/.go/bin/rot13
```
