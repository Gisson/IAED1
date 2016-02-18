
CFlags=-o
outputName=Project
destination=./

all: Proj1.c
	gcc Proj1.c $(CFlags) $(outputName) 

run: $(outputName)
	$(destination)$(outputName)

zip: 
	zip $(outputName) Proj1.c

clean: $(outputName)
	rm $(outputName)


