make:
	gcc -o fetch fetch.c -lm
install: make
	cp -f fetch /usr/local/bin/fetch
uninstall:
	rm -f /usr/local/bin/fetch
