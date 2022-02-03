# T9 dictionary - Modern C++ library

The library provides a simple solution for T9 dictionary.

## Usage
```
auto dictionary = T9::DictionaryLoader::loadFromFile("./10k_english.txt", T9::DictionaryImplementation::Trie);
const auto suggestions = dictionary->search({4, 3, 5, 5, 6});
for (const auto& word : suggestions)
{
    std::cout << word << '\n';
}
```

## Benchmarks

### Benchmark ran on Intel Core i7 pro:
```
Run on (12 X 5100 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 256 KiB (x6)
  L3 Unified 12288 KiB (x1)
Load Average: 2.21, 1.58, 1.27
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
--------------------------------------------------------------------
Benchmark                          Time             CPU   Iterations
--------------------------------------------------------------------
TrieDictionaryLoad10k        7433282 ns      7433090 ns           93
TrieDictionaryLoad466k     325256780 ns    325194005 ns            2
TrieDictionaryInsert             281 ns          281 ns      2743202
TrieDictionarySearch             435 ns          435 ns      1623716
HashMapDictionaryLoad10K     8868848 ns      8868193 ns           73
HashMapDictionaryLoad466k  463366146 ns    463350769 ns            2
HashMapDictionaryInsert          338 ns          338 ns      2032737
HashMapDictionarySearch          527 ns          527 ns      1372346
```

### Memcheck analysis
```
$ valgrind --leak-check=full ./trie_example 
==12552== Memcheck, a memory error detector
==12552== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12552== Using Valgrind-3.16.1 and LibVEX; rerun with -h for copyright info
==12552== Command: ./trie_example
==12552== 
hello
==12552== 
==12552== HEAP SUMMARY:
==12552==     in use at exit: 0 bytes in 0 blocks
==12552==   total heap usage: 29,367 allocs, 29,367 frees, 2,185,899 bytes allocated
==12552== 
==12552== All heap blocks were freed -- no leaks are possible
==12552== 
==12552== For lists of detected and suppressed errors, rerun with: -s
==12552== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
```
$ valgrind --leak-check=full ./hashmap_example 
==12544== Memcheck, a memory error detector
==12544== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==12544== Using Valgrind-3.16.1 and LibVEX; rerun with -h for copyright info
==12544== Command: ./hashmap_example
==12544== 
hello
==12544== 
==12544== HEAP SUMMARY:
==12544==     in use at exit: 0 bytes in 0 blocks
==12544==   total heap usage: 18,564 allocs, 18,564 frees, 971,833 bytes allocated
==12544== 
==12544== All heap blocks were freed -- no leaks are possible
==12544== 
==12544== For lists of detected and suppressed errors, rerun with: -s
==12544== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
