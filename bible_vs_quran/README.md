# Bible vs. Qu'ran
Fun little program I wrote to compare words in the bible to words in the qu'ran.


Bible (King James version) from Project Gutenberg
http://www.gutenberg.org/ebooks/10

Qu'ran by G. Margoliouth and J. M. Rodwell from Project Gutenberg
http://www.gutenberg.org/ebooks/2800



### Running it
Navigate into the bible_vs_quran directory and enter the commands in terminal
```
make
./main
```




### Things to look into
Future Features
 - get ranking for a word (should I compute it all ahead of time?)
 - percent of book that is that word
 - comparison to other text

Performance & Memory Alloc
 - allocate strlen(str) bytes for keys instead of constant 20 byte buffer
 - compute list of top words ahead of time and store in reverse hashtable?

Web
 - efficient enough to put of my 512MB RAM web server?
 - how can I use Express for the web server and have it interface with this code?

Java
 - write similar program in Java.  Compare runtimes.



### Journal
Bible
 - 5000000 buckets:   39MB memory     very few collisions               0.393 sec
 - 50000 buckets:     1.36MB memory   acceptable number of collisions   0.324 sec
 - 5000 buckets:      1MB memory      nearly 100% collisions            0.310 sec
 - 500 buckets:       972KB memory    it's getting ugly to look at      0.318 sec
 - 50 buckets:        960KB memory    definitely 100% now               0.429 sec
 - 10 buckets:        956KB memory    oh god...                         1.007 sec
 - 1 bucket:          912KB memory    lol                               4.239 sec

Decided on 5000 buckets, lots of collisions but mostly confined to 2 or 3 nodes per bucket

Quran
 - 5000000 buckets:   39MB memory     very few collisions               -
 - 50000 buckets:     1.18MB memory   acceptable number of collisions   -




