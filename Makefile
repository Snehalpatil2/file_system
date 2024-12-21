all: create_vd vd_add vd_get vd_ls
vd_ls: vd_ls.o arc.a
	gcc -o vd_ls vd_ls.o decode_file.o  -lm
vd_get: vd_get.o arc.a
	gcc -o vd_get vd_get.o  decode_file.o -lm
vd_add: vd_add.o arc.a 
	gcc -o vd_add vd_add.o encode.o decode_file.o -lm
create_vd: create_vd.o arc.a 
	gcc -o create_vd create_vd.o encode.o decode_file.o -lm
arc.a: encode.o decode_file.o
	ar rcs arc.a encode.o decode_file.o
encode.o: encode.c
	gcc -c encode.c
decode_file.o: decode_file.c
	gcc -c decode_file.c
vd_add.o: vd_add.c
	gcc -c vd_add.c
vd_get.o: vd_get.c
	gcc -c vd_get.c
vd_ls.o: vd_ls.c
	gcc -c vd_ls.c
clean:
	rm *.o *.a vd vd_add vd_get vd_ls create_vd


