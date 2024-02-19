make:
	gcc -o fetch fetch.c
install: make
	cp fetch /usr/bin/fetch
uninstall:
	rm /usr/bin/fetch