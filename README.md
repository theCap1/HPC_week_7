# HPC_week_7
## Homework for the 7th week

### 8 Recent Features: A Sneak Peek

#### 8.1 Arm Instruction Emulator

##### 8.1.2 Compile diffrent examples with different SVE vector lengths
The chosen examples from the lecture where `sve_example_0` and `sve_example_1`. With the right commands the output was as expected for different vector lengths. Without any modification `sve_example_1` would produce the exact same output as `sve_example_0`, because of the `ptrue p0.s` command which sets every fourth bit of the predicate register to one. Changing it to `ptrue p0.d` will only set every eigth bit to one. This enables every other half precision pipeline. The result is that only every other entry of the input array is copied to the output array.

##### 8.1.3 Counting instructions with `libinscount_emulated.so`
The examples from 8.1.2 where executed one more time with a vector length of 256 bits and the `libinscount_emulated.so` instruction and `only_from_app` argument. The result was as followed:

<details>
  <summary> example_0 output and counted instructions </summary>

```yaml
en / in / out: 0        /        2      /        2
en / in / out: 1        /        4      /        4
en / in / out: 2        /        6      /        6
en / in / out: 3        /        8      /        8
en / in / out: 4        /        10     /        10
en / in / out: 5        /        12     /        12
en / in / out: 6        /        14     /        14
en / in / out: 7        /        16     /        16
en / in / out: 8        /        18     /        0
en / in / out: 9        /        20     /        0
en / in / out: 10       /        22     /        0
en / in / out: 11       /        24     /        0
en / in / out: 12       /        26     /        0
en / in / out: 13       /        28     /        0
en / in / out: 14       /        30     /        0
en / in / out: 15       /        32     /        0
en / in / out: 16       /        34     /        0
en / in / out: 17       /        36     /        0
en / in / out: 18       /        38     /        0
en / in / out: 19       /        40     /        0
en / in / out: 20       /        42     /        0
en / in / out: 21       /        44     /        0
en / in / out: 22       /        46     /        0
en / in / out: 23       /        48     /        0
en / in / out: 24       /        50     /        0
en / in / out: 25       /        52     /        0
en / in / out: 26       /        54     /        0
en / in / out: 27       /        56     /        0
en / in / out: 28       /        58     /        0
en / in / out: 29       /        60     /        0
en / in / out: 30       /        62     /        0
en / in / out: 31       /        64     /        0
en / in / out: 32       /        66     /        0
en / in / out: 33       /        68     /        0
en / in / out: 34       /        70     /        0
en / in / out: 35       /        72     /        0
en / in / out: 36       /        74     /        0
en / in / out: 37       /        76     /        0
en / in / out: 38       /        78     /        0
en / in / out: 39       /        80     /        0
en / in / out: 40       /        82     /        0
en / in / out: 41       /        84     /        0
en / in / out: 42       /        86     /        0
en / in / out: 43       /        88     /        0
en / in / out: 44       /        90     /        0
en / in / out: 45       /        92     /        0
en / in / out: 46       /        94     /        0
en / in / out: 47       /        96     /        0
en / in / out: 48       /        98     /        0
en / in / out: 49       /        100    /        0
en / in / out: 50       /        102    /        0
en / in / out: 51       /        104    /        0
en / in / out: 52       /        106    /        0
en / in / out: 53       /        108    /        0
en / in / out: 54       /        110    /        0
en / in / out: 55       /        112    /        0
en / in / out: 56       /        114    /        0
en / in / out: 57       /        116    /        0
en / in / out: 58       /        118    /        0
en / in / out: 59       /        120    /        0
en / in / out: 60       /        122    /        0
en / in / out: 61       /        124    /        0
en / in / out: 62       /        126    /        0
en / in / out: 63       /        128    /        0
5033 instructions executed of which 121 were emulated instructions
```

</details>

<details>
  <summary> example_1 output and counted instructions </summary>

```yaml
en / in / out: 0        /        2      /        2
en / in / out: 1        /        4      /        0
en / in / out: 2        /        6      /        6
en / in / out: 3        /        8      /        0
en / in / out: 4        /        10     /        10
en / in / out: 5        /        12     /        0
en / in / out: 6        /        14     /        14
en / in / out: 7        /        16     /        0
en / in / out: 8        /        18     /        0
en / in / out: 9        /        20     /        0
en / in / out: 10       /        22     /        0
en / in / out: 11       /        24     /        0
en / in / out: 12       /        26     /        0
en / in / out: 13       /        28     /        0
en / in / out: 14       /        30     /        0
en / in / out: 15       /        32     /        0
en / in / out: 16       /        34     /        0
en / in / out: 17       /        36     /        0
en / in / out: 18       /        38     /        0
en / in / out: 19       /        40     /        0
en / in / out: 20       /        42     /        0
en / in / out: 21       /        44     /        0
en / in / out: 22       /        46     /        0
en / in / out: 23       /        48     /        0
en / in / out: 24       /        50     /        0
en / in / out: 25       /        52     /        0
en / in / out: 26       /        54     /        0
en / in / out: 27       /        56     /        0
en / in / out: 28       /        58     /        0
en / in / out: 29       /        60     /        0
en / in / out: 30       /        62     /        0
en / in / out: 31       /        64     /        0
en / in / out: 32       /        66     /        0
en / in / out: 33       /        68     /        0
en / in / out: 34       /        70     /        0
en / in / out: 35       /        72     /        0
en / in / out: 36       /        74     /        0
en / in / out: 37       /        76     /        0
en / in / out: 38       /        78     /        0
en / in / out: 39       /        80     /        0
en / in / out: 40       /        82     /        0
en / in / out: 41       /        84     /        0
en / in / out: 42       /        86     /        0
en / in / out: 43       /        88     /        0
en / in / out: 44       /        90     /        0
en / in / out: 45       /        92     /        0
en / in / out: 46       /        94     /        0
en / in / out: 47       /        96     /        0
en / in / out: 48       /        98     /        0
en / in / out: 49       /        100    /        0
en / in / out: 50       /        102    /        0
en / in / out: 51       /        104    /        0
en / in / out: 52       /        106    /        0
en / in / out: 53       /        108    /        0
en / in / out: 54       /        110    /        0
en / in / out: 55       /        112    /        0
en / in / out: 56       /        114    /        0
en / in / out: 57       /        116    /        0
en / in / out: 58       /        118    /        0
en / in / out: 59       /        120    /        0
en / in / out: 60       /        122    /        0
en / in / out: 61       /        124    /        0
en / in / out: 62       /        126    /        0
en / in / out: 63       /        128    /        0
5035 instructions executed of which 122 were emulated instructions
```

</details>

##### 8.1.4 Trace memory access

In this last part of 8.1 access of our example program to memory should be traced. This is done by applying the `libmemtrace_emulated.so` instruction and the `-roi` argument to within the ArmIE execution. A region of interest in which memory access shall be traced is previously definded by wrapping it with the `.inst 0x2520e020` and `.inst 0x2520e040` instructions. With the same output that we got in 8.1.3 with `example_1` the following memory access was logged with the predicate register setting `ptrue p0.s`:

<details>
  <summary> memory accesses from example_1 </summary>

```log
0, -1, 0, 1, 0, (nil), (nil)
1, 386513024, 0, 0, 4, 0xffffc39eb9a0, 0x400ef4
2, 386513024, 0, 0, 4, 0xffffc39eb9a8, 0x400ef4
3, 386513024, 0, 0, 4, 0xffffc39eb9b0, 0x400ef4
4, 386513024, 0, 0, 4, 0xffffc39eb9b8, 0x400ef4
5, 386513024, 0, 0, 4, 0xffffc39eb9c0, 0x400ef4
6, 386513024, 0, 0, 4, 0xffffc39eb9c8, 0x400ef4
7, 386513024, 0, 0, 4, 0xffffc39eb9d0, 0x400ef4
8, 386513024, 0, 0, 4, 0xffffc39eb9d8, 0x400ef4
9, 386513024, 0, 0, 4, 0xffffc39eb9e0, 0x400ef4
10, 386513024, 0, 0, 4, 0xffffc39eb9e8, 0x400ef4
11, 386513024, 0, 0, 4, 0xffffc39eb9f0, 0x400ef4
12, 386513024, 0, 0, 4, 0xffffc39eb9f8, 0x400ef4
13, 386513024, 0, 0, 4, 0xffffc39eba00, 0x400ef4
14, 386513024, 0, 0, 4, 0xffffc39eba08, 0x400ef4
15, 386513024, 0, 0, 4, 0xffffc39eba10, 0x400ef4
16, 386513024, 0, 0, 4, 0xffffc39eba18, 0x400ef4
17, -2, 0, 1, 0, (nil), (nil)
```

</details>

</br>

and the following with the predicate register setting `ptrue p0.d`:

<details>
  <summary> memory accesses from example_1 </summary>

```log
0, -1, 0, 1, 0, (nil), (nil)
1, 386513024, 0, 0, 4, 0xffffc39eb9a0, 0x400ef4
2, 386513024, 0, 0, 4, 0xffffc39eb9a8, 0x400ef4
3, 386513024, 0, 0, 4, 0xffffc39eb9b0, 0x400ef4
4, 386513024, 0, 0, 4, 0xffffc39eb9b8, 0x400ef4
5, 386513024, 0, 0, 4, 0xffffc39eb9c0, 0x400ef4
6, 386513024, 0, 0, 4, 0xffffc39eb9c8, 0x400ef4
7, 386513024, 0, 0, 4, 0xffffc39eb9d0, 0x400ef4
8, 386513024, 0, 0, 4, 0xffffc39eb9d8, 0x400ef4
9, 386513024, 0, 0, 4, 0xffffc39eb9e0, 0x400ef4
10, 386513024, 0, 0, 4, 0xffffc39eb9e8, 0x400ef4
11, 386513024, 0, 0, 4, 0xffffc39eb9f0, 0x400ef4
12, 386513024, 0, 0, 4, 0xffffc39eb9f8, 0x400ef4
13, 386513024, 0, 0, 4, 0xffffc39eba00, 0x400ef4
14, 386513024, 0, 0, 4, 0xffffc39eba08, 0x400ef4
15, 386513024, 0, 0, 4, 0xffffc39eba10, 0x400ef4
16, 386513024, 0, 0, 4, 0xffffc39eba18, 0x400ef4
17, -2, 0, 1, 0, (nil), (nil)
```

</details>

</br>

This makes sense because with `ptrue p0.s` all pipelines are enabled and all values that need to be loaded are connected in memory meaning the can be loaded with a single load. This can be seen in the single entry that says that 128 bytes were loaded which is the exact amount of 32 values. With `ptrue p0.d` on the other hand every other value is loaded and because these are not connected each of them need their own load. 
I suppose that the stores are not traced in these examples because they are no speciffic SVE instructions.

#### 8.2 Vector Length Agnostic Programming

The implemented function of *triad_low* is implemented in the kernel `triad_low.s`. It shall provide the same functionality as 

```C
void triad_high( uint64_t         i_n_values,
                float    const * i_a,
                float    const * i_b,
                float          * o_c ) {
    for( uint64_t l_va = 0; l_va < i_n_values; l_va++ ) {
        o_c[l_va] = i_a[l_va] + 2.0f * i_b[l_va];
    }
}
```

Testing was done within the `triad_driver.cpp`. For the different SVE vector lengths of 128, 256, 512, 1024 and 2048 bits array sizes of 13, 16, 25 and 50 worked without any problems.