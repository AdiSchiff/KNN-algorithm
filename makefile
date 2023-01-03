OBJS	= Server.o CanberraDistance.o ChebyshevDistance.o Data.o Distance.o EuclideanDistance.o ManhattanDistance.o Minkowski.o ReceiveVector.o Print.o VectorArithmetic.o StructVec.o
SOURCES	= Server.cpp CanberraDistance.cpp ChebyshevDistance.cpp Data.cpp Distance.cpp EuclideanDistance.cpp ManhattanDistance.cpp Minkowski.cpp ReceiveVector.cpp Print.cpp VectorArithmetic.cpp StructVec.cpp
HEADER	= CanberraDistance.h ChebyshevDistance.h Data.h Distance.h EuclideanDistance.h ManhattanDistance.h Minkowski.h ReceiveVector.h Print.h VectorArithmetic.h StructVec.h
OUTS	= server.out

OBJC	= Client.o
SOURCEC	= Client.cpp
OUTC	= client.out
CC	 = g++
FLAGS	 = -g -c -w


all: $(OBJS) $(OBJC)
	$(CC) -g $(OBJS) -o $(OUTS) $(LFLAGS)
	$(CC) -g $(OBJC) -o $(OUTC) $(LFLAGS)

Server.o: Server.cpp
	$(CC) $(FLAGS) Server.cpp -std=c++11

CanberraDistance.o: CanberraDistance.cpp
	$(CC) $(FLAGS) CanberraDistance.cpp -std=c++11

ChebyshevDistance.o: ChebyshevDistance.cpp
	$(CC) $(FLAGS) ChebyshevDistance.cpp -std=c++11

Data.o: Data.cpp
	$(CC) $(FLAGS) Data.cpp -std=c++11

Distance.o: Distance.cpp
	$(CC) $(FLAGS) Distance.cpp -std=c++11

EuclideanDistance.o: EuclideanDistance.cpp
	$(CC) $(FLAGS) EuclideanDistance.cpp -std=c++11

/*Main.o: Main.cpp
	$(CC) $(FLAGS) Main.cpp -std=c++11*/

ManhattanDistance.o: ManhattanDistance.cpp
	$(CC) $(FLAGS) ManhattanDistance.cpp -std=c++11

Minkowski.o: Minkowski.cpp
	$(CC) $(FLAGS) Minkowski.cpp -std=c++11

ReceiveVector.o: ReceiveVector.cpp
	$(CC) $(FLAGS) ReceiveVector.cpp -std=c++11

Print.o: Print.cpp
	$(CC) $(FLAGS) Print.cpp -std=c++11

VectorArithmetic.o: VectorArithmetic.cpp
	$(CC) $(FLAGS) VectorArithmetic.cpp -std=c++11

StructVec.o: StructVec.cpp
	$(CC) $(FLAGS) StructVec.cpp -std=c++11

Client.o: Client.cpp
	$(CC) $(FLAGS) Client.cpp -std=c++11

clean:
	rm -f $(OBJS) $(OUTS)
	rm -f $(OBJC) $(OUTC)
