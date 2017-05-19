objects = bd_tool.o broadcast.o main.o
sender: $(objects)
	gcc -o sender.out $(objects) -l stdc++ -DSENDER

receiver : $(objects)
	gcc -o receiver.out $(objects) -l stdc++ -USENDER	

.PHONY : clean
clean :
	rm -rf *.dSYM
	rm *.out
	rm *.o
