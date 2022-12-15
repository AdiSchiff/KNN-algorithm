all:
	g++ -std=c++11 *.cpp  -o a.out
	
run: a.out
	./a.out 3 datasets/iris/iris_classified.csv MAN

run-beans: a.out
	./a.out 3 datasets/beans/beans_Classified.csv AUC
	
run-iris: a.out
	./a.out 3 datasets/iris/iris_classified.csv MAN

run-wine: a.out
	./a.out 3 datasets/wine/wine_Classified.csv CHB

clean: a.out
	rm -f a.out
