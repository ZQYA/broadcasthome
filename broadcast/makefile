objects = $(patsubst %.cpp,%.o,$(wildcard *.cpp)) 
sources = $(wildcard *.cpp)
VPATH = data_trans
sender: $(objects)
	gcc -o sender.out $(objects) -l stdc++ -DSENDER

receiver : $(objects)
	gcc -o receiver.out $(objects) -l stdc++ -USENDER	
*.o: $(sources)
	gcc -c $(sources) -o $(objects) -l stdc++ -DSENDER  
.PHONY : clean
clean :
	-rm -rf *.dSYM
	-rm *.out
	-rm *.o
