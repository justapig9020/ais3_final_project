

run1: test libmcount.so 
	LD_PRELOAD=./libmcount.so  ./test

run: test libmcount.so dt
	LD_PRELOAD=./libmcount.so ./dt ./test

dt: dt.c libmcount.so
	gcc -o dt dt.c ./libmcount.so

libmcount.so: malloc_count.c struct.c
	gcc -D_GNU_SOURCE -shared -fPIC -o libmcount.so malloc_count.c struct.c  -ldl

test: test.c
	gcc -o test test.c
    
    
clean: dt libmcount.so test
	rm dt libmcount.so test
