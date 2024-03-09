make:
	gcc -o fetch fetch.c -lm
install: make
	cp fetch /usr/local/bin/fetch
uninstall:
	rm /usr/local/bin/fetch
