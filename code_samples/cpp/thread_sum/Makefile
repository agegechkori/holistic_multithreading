sum_ints_lib = libsum_ints.a
benchmark = sum_ints_benchmark

run_main: sum_ints_main
	./sum_ints_main

sum_ints_main: sum_ints_main.cc $(sum_ints_lib)
	clang++ sum_ints_main.cc -std=c++14 -L. -lsum_ints -lpthread -O3 -o sum_ints_main

$(sum_ints_lib): sum_ints.h sum_ints.cc
	clang++ -c -O3 -std=c++14 sum_ints.cc
	ar rcs $(sum_ints_lib) sum_ints.o

$(benchmark): sum_ints_benchmark.cc $(sum_ints_lib)
	clang++ sum_ints_benchmark.cc -std=c++14 -lbenchmark -L. -lsum_ints -lpthread -O3 -o $(benchmark)

run_benchmark: $(benchmark)
	./sum_ints_benchmark

static: sum_ints_main.cc $(sum_ints_lib)
	clang++ sum_ints_main.cc -std=c++14 -L. -lsum_ints -lpthread -O3 -o sum_ints_main_static

asm: sum_ints.cc
	clang++ sum_ints.cc -std=c++14 -S

clean:
	rm -f *.a *.o *.s sum_ints_main sum_ints_main_static sum_ints_benchmark
