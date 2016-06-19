hello:
	g++ -Wall -std=c++11 src/drive.cpp src/world.cpp -o bin/hello -I include/
clean:
	rm bin/hello
cdata:
	rm data/out
run:
	./bin/hello Carlos