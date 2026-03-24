# lang-fix

![Open Source Garbage](https://img.shields.io/badge/open--source-garbage-red)

translate thai keyboard &lt;--> eng keyboard
Works on my machine (and yours, if you're cool enough)

----
## Why?

fix problem forgot to change languge when type something
for example :

็ำสสน = Hello

l;ylfu = สวัสดี

so i create this ctl tools

---

## How to use

easy just type

```
langfix '[whatever]'
```

example : 
```
langfix 'l;ylfuF]d'
```

---

## How to install

1. download sourcecode
2. compile source code
```
gcc langfix.c -o langfix
```
4. give it permisson to run
```
chmod +x langfix
```
5. move it to /usr/bin or /usr/local/bin (depend on your unix like os but if you're using windows i have noidea how)
```
sudo cp langfix /usr/bin
```
6. yay it works

---

License MIT 
