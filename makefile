OBJS	= Server.o CanberraDistance.o ChebyshevDistance.o Distance.o EuclideanDistance.o ManhattanDistance.o Minkowski.o ReceiveVector.o VectorArithmetic.o StructVec.o Cli.o Command.o DefaultIO.o KnnDetails.o SocketIO.o
SOURCES	= Server.cpp CanberraDistance.cpp ChebyshevDistance.cpp Distance.cpp EuclideanDistance.cpp ManhattanDistance.cpp Minkowski.cpp ReceiveVector.cpp VectorArithmetic.cpp StructVec.cpp Cli.cpp Command.cpp DefaultIO.cpp KnnDetails.cpp SocketIO.cpp
HEADER	= CanberraDistance.h ChebyshevDistance.h Distance.h EuclideanDistance.h ManhattanDistance.h Minkowski.h ReceiveVector.h VectorArithmetic.h StructVec.h Cli.h Command.h DefaultIO.h KnnDetails.h SocketIO.h
OUTS	= server.out

OBJC	= Client.o CommandClient.o DefaultIO.o SocketIO.o
SOURCEC	= Client.cpp CommandClient.cpp DefaultIO.cpp SocketIO.cpp
HEADERC = CommandClient.h DefaultIO.h SocketIO.h
OUTC	= client.out
CC	 = g++ -pthread
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

Distance.o: Distance.cpp
	$(CC) $(FLAGS) Distance.cpp -std=c++11

EuclideanDistance.o: EuclideanDistance.cpp
	$(CC) $(FLAGS) EuclideanDistance.cpp -std=c++11

ManhattanDistance.o: ManhattanDistance.cpp
	$(CC) $(FLAGS) ManhattanDistance.cpp -std=c++11

Minkowski.o: Minkowski.cpp
	$(CC) $(FLAGS) Minkowski.cpp -std=c++11

ReceiveVector.o: ReceiveVector.cpp
	$(CC) $(FLAGS) ReceiveVector.cpp -std=c++11

VectorArithmetic.o: VectorArithmetic.cpp
	$(CC) $(FLAGS) VectorArithmetic.cpp -std=c++11

StructVec.o: StructVec.cpp
	$(CC) $(FLAGS) StructVec.cpp -std=c++11

Client.o: Client.cpp
	$(CC) $(FLAGS) Client.cpp -std=c++11

Cli.o: Cli.cpp
	$(CC) $(FLAGS) Cli.cpp -std=c++11

Command.o: Command.cpp
	$(CC) $(FLAGS) Command.cpp -std=c++11

CommandClient.o: CommandClient.cpp
	$(CC) $(FLAGS) CommandClient.cpp -std=c++11

DefaultIO.o: DefaultIO.cpp
	$(CC) $(FLAGS) DefaultIO.cpp -std=c++11

KnnDetails.o: KnnDetails.cpp
	$(CC) $(FLAGS) KnnDetails.cpp -std=c++11

SocketIO.o: SocketIO.cpp
	$(CC) $(FLAGS) SocketIO.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUTS)
	rm -f $(OBJC) $(OUTC)