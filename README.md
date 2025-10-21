## What is this?

<img src="https://github.com/ghumphr/RedisAFLplusplus/blob/main/docs/resources/american_fuzzy_lop_on_redis.png?raw=true" align="right" width="440px"/>

This is a fork of AFL++ enhanced with distributed power schedules by Geoffrey Humphreys for a thesis in Cybersecurity at the University of Nebraska at Omaha.

## How do I install it?

You will need hiredis and a functional mmap() to compile it. At present, AFL++ requires a working fork() and SysV shared memory. If you want to fuzz on Windows, I recommend running AFL++ in WSL and using [Fpicker](https://github.com/ttdennis/fpicker) to fuzz Windows programs with Frida instrumentation.

    git clone https://github.com/ghumphr/RedisAFLplusplus
    cd RedisAFLplusplus
    make USE_REDIS=1
    sudo make install

## How do I use it?

    $ afl-fuzz -J n_fuzz.bin -r redis.example.com -R 6379 [...]

## Legal

Attributions are due to the authors. Please see the original sources and documentation here: https://github.com/AFLplusplus/AFLplusplus

You are free to copy, modify, and distribute AFL++ with attribution under the
terms of the Apache-2.0 License. See the [LICENSE](LICENSE) for details.

