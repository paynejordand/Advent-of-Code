a: a.c
	gcc -Wall -g -o a a.c -lm

runA: a
	./a < input.txt

debugA: a
	gdb ./a

b: b.c
	gcc -Wall -g -o b b.c -lm

runB: b
	./b < input.txt

debugB: b
	gdb ./b

clean:
	rm -f a
	rm -f b
