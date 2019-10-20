OBJECTS : subsys main1 main2 main3


subsys : 
	cd lib; $(MAKE)


main1 : 
	gcc -I./lib -L./lib main.c -ltest -o main1


main2 :
	gcc -I./lib -L./lib main.c -Wl,-rpath,/home/ubuntu/test3/lib -l pr1 -o main2
	

main3 : 
	gcc -rdynamic main2.c -ldl -o main3


clean : 
	cd lib; $(MAKECLEAN)
	rm -f main1 main2 main3

