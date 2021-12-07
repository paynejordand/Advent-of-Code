a: a.c
	gcc -Wall -g -o a a.c

runA: a
	./a < input.txt

debugA: a
	gdb ./a

b: b.c
	gcc -Wall -g -o b b.c

runB: b
	./b < input.txt

debugB: b
	gdb ./b

clean:
	rm -f a
	rm -f b
