all : hello.exe

hello_world.c : create.lua 
	lua create_4.lua $< > $@

hello.exe : hello_world.c
	gcc -o $@ -m32 hello_world.c -Ilua/include -Llua/lib -llua5.1

clean:
	del hello_world.c hello.exe 