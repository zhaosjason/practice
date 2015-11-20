# Bible vs. Qu'ran
Fun little program I wrote to compare words in the bible with words in the qu'ran.

### Things to look into
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
 - 5000000 buckets: 39MB memory, very few collisions
 - 50000 buckets: 1.18MB memory, acceptable number of collision
s



