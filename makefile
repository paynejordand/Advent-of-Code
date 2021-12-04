compA: a.c
	gcc -Wall -g -o a a.c

runA:
	./a < input.txt

debugA:
	gdb ./a

compB: b.c
	gcc -Wall -g -o b b.c

runB:
	./b < input.txt

debugB:
	gdb ./b

clean:
	rm -f a
	rm -f b