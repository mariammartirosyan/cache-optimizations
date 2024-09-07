all: naive aware oblivious optimized

naive:
	gcc matrix_transpose_main.c -O0 -D_N -o naive

aware:
	gcc matrix_transpose_main.c -O0 -D_A -o aware

oblivious:
	gcc matrix_transpose_main.c -O0 -D_O -o oblivious

optimized:
	gcc matrix_transpose_main.c -O0 -D_OPTIMIZED -o optimized

clean:
	rm naive
	rm aware
	rm oblivious
	rm optimized