a: a.c
	gcc -Wall -g -o a a.c -lm

ra: a
	./a < input.txt

da: a
	gdb ./a

b: b.c
	gcc -Wall -g -o b b.c -lm

rb: b
	./b < input.txt

db: b
	gdb ./b

clean:
	rm -f a
	rm -f b
