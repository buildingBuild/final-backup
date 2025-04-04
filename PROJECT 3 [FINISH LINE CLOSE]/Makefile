output: main.o Book.o BookCollections.o customerCollection.o customer.o Loan.o LoanCollections.o
	g++ main.o Book.o BookCollections.o customerCollection.o customer.o Loan.o LoanCollections.o -o output

main.o: main.cpp Book.h BookCollections.h customer.h customerCollection.h LoanCollections.h Loan.h
	g++ -c main.cpp -o main.o

Book.o: Book.cpp Book.h
	g++ -c Book.cpp -o Book.o

BookCollections.o: BookCollections.cpp BookCollections.h Book.h
	g++ -c BookCollections.cpp -o BookCollections.o 

customerCollection.o: customerCollection.cpp customer.h customerCollection.h
	g++ -c customerCollection.cpp -o customerCollection.o

customer.o: customer.cpp customer.h customerCollection.h
	g++ -c customer.cpp -o customer.o
	
Loan.o: Loan.cpp LoanCollections.h Loan.h
	g++ -c Loan.cpp -o Loan.o

LoanCollections.o: LoanCollections.cpp Loan.h LoanCollections.h customerCollection.h customer.h BookCollections.h customerCollection.h
	g++ -c LoanCollections.cpp -o LoanCollections.o




clean:
	rm *.o output