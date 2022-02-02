#include <benchmark/benchmark.h>

#include <t9trie/DictionaryLoader.hpp>

static void TrieDictionaryLoad(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(T9::DictionaryLoader::loadFromFile("./english.txt", T9::DictionaryImplementation::Trie));
    }
}
BENCHMARK(TrieDictionaryLoad);

static void TrieDictionaryInsert(benchmark::State& state) {
    std::stringstream ss;
    auto dict = T9::DictionaryLoader::loadFromStream(ss, T9::DictionaryImplementation::Trie);
    for (auto _ : state) {
        benchmark::DoNotOptimize(dict->insert("hello"));
    }
}
BENCHMARK(TrieDictionaryInsert);

static void TrieDictionarySearch(benchmark::State& state) {
    auto dict = T9::DictionaryLoader::loadFromFile("./english.txt", T9::DictionaryImplementation::Trie);
    for (auto _ : state) {
        benchmark::DoNotOptimize(dict->search({4, 3, 5, 5, 6}));
    }
}
BENCHMARK(TrieDictionarySearch);

static void HashMapDictionaryLoad(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(T9::DictionaryLoader::loadFromFile("./english.txt", T9::DictionaryImplementation::HashMap));
    }
}
BENCHMARK(HashMapDictionaryLoad);

static void HashMapDictionaryInsert(benchmark::State& state) {
    std::stringstream ss;
    auto dict = T9::DictionaryLoader::loadFromStream(ss, T9::DictionaryImplementation::HashMap);
    for (auto _ : state) {
        benchmark::DoNotOptimize(dict->insert("hello"));
    }
}
BENCHMARK(HashMapDictionaryInsert);

static void HashMapDictionarySearch(benchmark::State& state) {
    auto dict = T9::DictionaryLoader::loadFromFile("./english.txt", T9::DictionaryImplementation::HashMap);
    for (auto _ : state) {
        benchmark::DoNotOptimize(dict->search({4, 3, 5, 5, 6}));
    }
}
BENCHMARK(HashMapDictionarySearch);

BENCHMARK_MAIN();
